#include <unistd.h>
#include <string.h>

int main() {
    const char *msg_out = "This is a message to STDOUT (descriptor 1)\n";
    const char *msg_err = "This is an ERROR message to STDERR (descriptor 2)\n";

    write(1, msg_out, strlen(msg_out));

    write(2, msg_err, strlen(msg_err));

    return 0;
}
