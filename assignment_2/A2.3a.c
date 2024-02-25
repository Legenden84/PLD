#include <stdio.h>

int x = 10;

int functionCall1(int x) {
    return x;
}

int functionCall2(int x) {
    return x;
}

int main() {
    printf("functionCall1() { return x; } = %d\n", functionCall1(x));
    int x = 20;
    printf("functionCall2() { return x; } = %d\n", functionCall2(x));

    return 0;
}
