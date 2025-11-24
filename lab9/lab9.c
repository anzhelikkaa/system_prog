#include <unistd.h>
#include <string.h>

int main() {
    const char *msg_out = "This is a message to STDOUT (descriptor 1)\n";
    const char *msg_err = "This is an ERROR message to STDERR (descriptor 2)\n";

    // 1 - це стандартний дескриптор stdout
    // write приймає: дескриптор, буфер, кількість байт
    write(1, msg_out, strlen(msg_out));

    // 2 - це стандартний дескриптор stderr
    write(2, msg_err, strlen(msg_err));

    return 0;
}