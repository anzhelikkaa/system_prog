#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    char input[50] = "ThisIsAVeryLongString";
    strcpy(buffer, input); // небезпечно!
    printf("Buffer: %s\n", buffer);
    return 0;
}
