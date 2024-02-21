
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
