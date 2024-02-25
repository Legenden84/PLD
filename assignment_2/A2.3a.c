#include <stdio.h>

int x = 10;

int functionCall() {
    return x;
}

void updateScope(int newScope) {
    x = newScope;
}

int main() {
    printf("functionCall() - global variable x: %d\n", functionCall());
    updateScope(20);
    printf("functionCall() - local variable x: %d\n", functionCall());

    return 0;
}
