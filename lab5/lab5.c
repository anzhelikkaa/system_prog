#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int fd[2];
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
        close(fd[1]);
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
        close(fd[0]);
        const char *msg = "Hello from parent";
        if (write(fd[1], msg, strlen(msg)) == -1) {
            perror("write");
        }
        close(fd[1]);
        wait(NULL);
        return 0;
    }
}
