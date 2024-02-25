#include <stdio.h>

int x = 5;

void add() {
    x = x + x;
}

void nestedAdd() {
    x = 100;
    printf("example 2:\n");
    printf("  x = %d\n", x);
    add();
    printf("  x = %d\n", x);
    add();
    printf("  x = %d\n", x);
}

int main() {
    printf("example 1:\n");
    printf("  x = %d\n", x);
    add();
    printf("  x = %d\n", x);
    add();
    printf("  x = %d\n", x);
    nestedAdd();

    return 0;
}