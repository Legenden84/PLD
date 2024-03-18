#include <stdio.h>
#include <stdarg.h>

int sum(int num, ...);

int sum(int num, ...) {
    int total = 0;
    va_list valist;
    va_start(valist, num);

    for (int i = 0; i < num; i++) {
        total += va_arg(valist, int);
    }

    va_end(valist);
    return total;
}

int main() {
    printf("sum(1, 2, 3, 4, 5) = %d\n", sum(5, 1, 2, 3, 4, 5));
    printf("sum(5, 10, 15, 20, 25) = %d\n", sum(5, 5, 10, 15, 20, 25));
    return 0;
}