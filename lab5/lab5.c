// task1_pipe_basic.c
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int fd[2]; // fd[0] - для читання, fd[1] - для запису
    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Дочірній процес: читає з pipe
        close(fd[1]); // закриваємо сторону запису
        char buf[128];
        ssize_t n = read(fd[0], buf, sizeof(buf)-1);
        if (n >= 0) {
            buf[n] = '\0';
            printf("Child received: %s\n", buf);
        } else {
            perror("read");
        }
        close(fd[0]);
        return 0;
    } else {
        // Батьківський процес: пише в pipe
        close(fd[0]); // закриваємо сторону читання
        const char *msg = "Hello from parent";
        if (write(fd[1], msg, strlen(msg)) == -1) {
            perror("write");
        }
        close(fd[1]);
        wait(NULL);
        return 0;
    }
}
