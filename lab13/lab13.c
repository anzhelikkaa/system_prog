#include <stdio.h>

int main() {
    char buffer[10];
    printf("Enter string: ");
    scanf("%s", buffer); // введення без перевірки довжини
    printf("You entered: %s\n", buffer);
    return 0;
}
