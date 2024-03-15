#include <stdio.h>

int x = 10;

int functionCall1(int x) {
    return x;
}

int functionCall2(int x) {
    return x;
}

int main() {
    printf("example 1:\n");
    printf("  functionCall1() { return x; } = %d\n", functionCall1(x));
    x = x + 20;
    printf("example 2:\n");
    printf("  functionCall2() { return x; } = %d\n", functionCall2(x));

    return 0;
}
