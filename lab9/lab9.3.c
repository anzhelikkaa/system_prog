#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h> // Бібліотека для кодів помилок
#include <string.h>

int main() {
    int fd = open("test_close.txt", O_WRONLY | O_CREAT, 0644);
    if (fd < 0) return 1;

    write(fd, "Data", 4);
    
    // Закриваємо дескриптор
    printf("Closing file descriptor %d...\n", fd);
    close(fd);

    // Спроба використати закритий дескриптор
    printf("Attempting to write to closed FD...\n");
    ssize_t res = write(fd, "More Data", 9);

    if (res < 0) {
        // EBADF = Bad File Descriptor
        printf("Error caught: %s (Errno: %d)\n", strerror(errno), errno);
        if (errno == EBADF) {
            printf("Confirmed: Cannot use closed file descriptor.\n");
        }
    } else {
        printf("Unexpected success!\n");
    }
    
    unlink("test_close.txt");
    return 0;
}