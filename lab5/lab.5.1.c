// task2_exec_ls.c
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
        // Дочірній процес: замінює себе на "ls -l"
        execlp("ls", "ls", "-l", (char*)NULL);
        // Якщо ми тут — exec не вдався
        perror("execlp");
        return 1;
    } else {
        // Батьківський процес: чекає завершення дитини
        int status = 0;
        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid");
            return 1;
        }
        if (WIFEXITED(status)) {
            printf("Child exited with code %d\n", WEXITSTATUS(status));
        }
        return 0;
    }
}
