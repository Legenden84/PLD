#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define __STDC_FORMAT_MACROS
#include <inttypes.h>

uint64_t heap[200]; /* deliberately small heap */
uint64_t *heapStart = heap;
uint64_t *heapEnd = heap+199;

uint64_t *freelist = heap;


void initialize_freelist() {
  *freelist = 0xfff09c169414613;
  *(freelist+1) = 200;
  freelist +=2;
}


uint64_t *isHeapPointer(uint64_t *value) {

  if (value < heapStart) return 0;
  if (value > heapEnd) return 0;

  uint64_t *value_original = value;
  while (value >= heapStart)  {
    if (*value != 0xfff09c169414613) {
      value = (value - 1);
    } else {
        // this is the size field address
        value = value + 1;

        uint64_t size_field_size = *value;

        // if we have an original pointer,
        // which is larger than the nearest allocated slot,
        // then the pointer does not refer to an object
        // that is allocated to the heap, but a free space.
        // below condition is value-1 = magic word field
        if (value_original < (size_field_size + value-1)) {
          return (value + 1); // this is the first field pointer
        } else {
          return 0;
        }
    }
  }
  return 0;
}



uint64_t firstGlobal[100] = {0}; /* simulated global variables */
uint64_t *lastGlobal = firstGlobal+99;

uint64_t stackBottom[100] = {0}; /* simulated stack variables */
uint64_t *stackTop = stackBottom+99;

int stack_size = 1000; /* work stack for GC to use */

void mark() {
  uint64_t *stack[stack_size];
  uint64_t stackPointer = 0;
  uint64_t *tmp;
  uint64_t size;

  /* add root set to work stack */
  for (uint64_t *i = firstGlobal; i <= lastGlobal; i++) {
    // we get a 0 or a pointer to the first field (which is pushed to stack)
    uint64_t *resGlobal = isHeapPointer((uint64_t*) *i);
    if (resGlobal != 0) {
      stack[stackPointer++] = resGlobal;
    }
  }
  for (uint64_t *i = stackBottom; i <= stackTop; i++) {
    uint64_t *resStack = isHeapPointer((uint64_t*) *i);
    if (resStack != 0) {
      stack[stackPointer++] = resStack;
    }
  }
  printf("root set pushed, stackPointer == %"PRIx64"\n", stackPointer);

  while (stackPointer > 0) {
    tmp = stack[--stackPointer];
    size = *(tmp-1);
    if ((size & 0x8000000000000000) == 0) {
      /* if mark bit is clear */
      /* add pointer fields to work stack */
      for (uint64_t *i = tmp; i < tmp + size - 2; i++) {
        uint64_t *resTmp = isHeapPointer((uint64_t*) *i);
        if (resTmp != 0) {
	        stack[stackPointer++] = resTmp;
        }
      }
      *(tmp-1) |= 0x8000000000000000; /* and set mark bit */
    }
  }
}


void sweep() {
  uint64_t *current = heapStart+2;
  uint64_t size, size2;
  freelist = NULL;
  while (current <= heapEnd) {
    size = *(current-1);
    if (size & 0x8000000000000000) { /* mark is set */
      size &= 0x7fffffffffffffff;
      *(current-1) = size; /* clear mark */
      printf("marked, size == %"PRIx64", content == %"PRIx64"\n", size, *current);
      current += size;
    } else { /* mark is clear */
      printf("unmarked\n");
      while (current+size < heapEnd &&
             ((size2 = *(current+size-1))
	      & 0x8000000000000000) == 0) {
        *(current+size-2) = 0; /* clear magic word */
        size += size2; /* join blocks */
	printf("size ==  %"PRIx64"\n", size);
      }
      /* add block to freelist */
      *(current-1) = size;
      *current = (uint64_t) freelist;
      freelist = current;
      current += size;
    }
  }
}

void gc() {
  mark();
  printf("mark done\n");
  sweep();
  printf("sweep done: freelist == %"PRIx64"\n",freelist-heapStart);
}

uint64_t *allocate(uint64_t size) {

  size += 2; /* make room for header words */
  for (int i = 0; i<2; i++) {
    uint64_t *previous = NULL;
    uint64_t *current = freelist;
    uint64_t currentSize = 0;
    printf("alloc: %d, size = %ld\n",i, size);

    while (current != NULL) {

      currentSize = *(current-1); // this is the size available in freelist which is a reference to the heap, which has size 200?
      if (currentSize > size+2) { /* split object */ //vi har brug for 2 ekstra for at kunne splitte
          // we set magic word field
          *(current+currentSize-size-2) = 0xfff09c169414613;
          // we set size field
          *(current+currentSize-size-1) = size;
          *(current-1) -= size;
          return current+(currentSize-size);

      } else if (currentSize >= size) { /* return object */
          if (previous == NULL) freelist = (uint64_t*) *current;
          else *previous = *current;
          return current;

      } else { /* find next object in freelist */
          previous = current;
          current = (uint64_t*) *current;
      }
    }
    if (i > 0) return 0; /* already tried calling gc */
    gc(); /* call garbage collector */
  }
}

// main taken from newmain.c
int main() {
  uint64_t *ll = NULL;
  uint64_t *cc = NULL;

  initialize_freelist();

  for (int i = 0; i<60; i++) {
    if ((cc = allocate((3*i)%11+3)) != 0) {
      printf("allocation successful: %ld\n", cc - heapStart);
      cc[0] = 0x1001*i;
      if (i%13 == 0) cc[1] =  firstGlobal[i%17]; else cc[1] = 0;
      ll = cc;
      firstGlobal[i%17] = (uint64_t) (ll+i%3);
    } else {
      printf("Allocation failed at i == %d, size = %d\n", i, (3*i)%11+2);
      exit(0);
    }
  }
}


