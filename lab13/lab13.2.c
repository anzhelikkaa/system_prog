#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    char input[50] = "SafeString";

    // копіюємо не більше 9 символів + '\0'
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0'; // гарантуємо завершення рядка

    printf("Buffer: %s\n", buffer);
    return 0;
}
