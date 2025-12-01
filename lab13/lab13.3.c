#include <stdio.h>

int main() {
    char buffer[20];
    printf("Enter string: ");
    if (fgets(buffer, sizeof(buffer), stdin)) {
        printf("You entered: %s\n", buffer);
    }
    return 0;
}
