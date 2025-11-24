#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Помилка відкриття файлу");
        return 1;
    }

    const char *msg = "Hello, File!\n";
    if (write(fd, msg, strlen(msg)) == -1) {
        perror("Помилка запису");
        close(fd);
        return 1;
    }

    printf("Запис виконано успішно!\n");
    close(fd);
    return 0;
}

