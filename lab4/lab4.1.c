#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork(); // створює новий процес

    if (pid == 0) {
        // Дочірній процес (fork повертає 0 у дитини)
        printf("Це дитина. PID=%d, PPID=%d\n", getpid(), getppid());
    } else if (pid > 0) {
        // Батьківський процес (fork повертає PID дитини)
        printf("Це батько. PID=%d, PPID=%d\n", getpid(), getppid());
    } else {
        // Якщо fork не вдався
        perror("fork failed");
    }
    return 0;
}
