#include <stdio.h>

int square(int n) {
    return n * n;
}

int main() {
    int a = 5;
    int b = square(a);
    printf("Result: %d\n", b);
    return 0;
}
