#include <stdio.h>

int x = 5;

void add() {
    x = x + x;
}

int main() {
    printf("example 1:\n");
    printf("  x = %d\n", x);
    add();
    printf("  x = %d\n", x);
    add();
    printf("  x = %d\n", x);

    x = x + 95;

    printf("example 2:\n");
    printf("  x = %d\n", x);
    add();
    printf("  x = %d\n", x);
    add();
    printf("  x = %d\n", x);

    return 0;
}