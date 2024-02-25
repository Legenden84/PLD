#include <stdio.h>

int functionDefinition = 10;

int functionCall1() {
    return functionDefinition;
}

int functionCall2() {
    return functionDefinition;
}

int main() {
    printf("functionCall1() { return functionDefinition; } = %d\n", functionCall1());
    functionDefinition = 20;
    printf("functionCall2() { return functionDefinition; } = %d\n", functionCall2());

    return 0;
}
