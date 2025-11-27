#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        execlp("ls", "ls", "-l", (char*)NULL);
        perror("execlp");
        return 1;
    } else {
        int status = 0;
        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid");
            return 1;
        }
        if (WIFEXITED(status)) {
            printf("Child exited %d\n", WEXITSTATUS(status));
        }
        return 0;
    }
}
