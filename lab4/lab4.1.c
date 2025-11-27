#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork(); 

    if (pid == 0) {
        printf("дитина. PID=%d, PPID=%d\n", getpid(), getppid());
    } else if (pid > 0) {
        printf("батько. PID=%d, PPID=%d\n", getpid(), getppid());
    } else {
        perror("fork failed");
    }
    return 0;
}
