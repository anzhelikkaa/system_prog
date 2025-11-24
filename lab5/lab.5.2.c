// task3_pipeline_ls_grep.c
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid1 = fork(); // процес для "ls"
    if (pid1 == -1) { perror("fork"); return 1; }

    if (pid1 == 0) {
        // Дитина 1: ls -> пише у pipe
        close(fd[0]);                // закриваємо читання
        if (dup2(fd[1], STDOUT_FILENO) == -1) { // перенаправляємо stdout у pipe
            perror("dup2");
            return 1;
        }
        close(fd[1]); // зайвий дескриптор
        execlp("ls", "ls", (char*)NULL);
        perror("execlp ls");
        return 1;
    }

    pid_t pid2 = fork(); // процес для "grep .c"
    if (pid2 == -1) { perror("fork"); return 1; }

    if (pid2 == 0) {
        // Дитина 2: читає з pipe -> grep .c
        close(fd[1]);                // закриваємо запис
        if (dup2(fd[0], STDIN_FILENO) == -1) { // перенаправляємо stdin з pipe
            perror("dup2");
            return 1;
        }
        close(fd[0]);
        execlp("grep", "grep", ".c", (char*)NULL);
        perror("execlp grep");
        return 1;
    }

    // Батько: закриває обидва кінці і чекає
    close(fd[0]);
    close(fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return 0;
}
