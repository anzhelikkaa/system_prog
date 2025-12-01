#include <stdio.h>

int main() {
    int a = 10;
    int b = 5;
    int result;

    printf("Start of the program\n");

    b = b - 5;
    
    result = a / b;

    printf("Result is: %d\n", result);
    return 0;
}