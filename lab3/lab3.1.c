#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Помилка відкриття файлу");
        return 1;
    }

    char buf[100];
    int n = read(fd, buf, sizeof(buf)-1);
    if (n == -1) {
        perror("Помилка читання");
        close(fd);
        return 1;
    }

    buf[n] = '\0';
    printf("Вміст файлу:\n%s\n", buf);

    close(fd);
    return 0;
}
