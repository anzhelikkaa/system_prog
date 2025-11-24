#include <stdio.h>   // стандартний ввід/вивід
#include <unistd.h>  // функції роботи з процесами (getpid, getppid)

int main() {
    printf("PID: %d\n", getpid());   // getpid() повертає ідентифікатор поточного процесу
    printf("PPID: %d\n", getppid()); // getppid() повертає ідентифікатор батьківського процесу
    return 0;
}
