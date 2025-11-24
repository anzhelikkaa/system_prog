// task4_pipe_numbers_sum.c
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    int nums[] = {1, 2, 3, 4, 5};
    size_t count = sizeof(nums) / sizeof(nums[0]);

    pid_t pid = fork();
    if (pid == -1) { perror("fork"); return 1; }

    if (pid == 0) {
        // Дитина: читає масив і рахує суму
        close(fd[1]); // не пишемо
        // Спершу читаємо кількість елементів (щоб знати скільки байтів чекати)
        size_t n = 0;
        if (read(fd[0], &n, sizeof(n)) != sizeof(n)) {
            perror("read count");
            return 1;
        }
        long long sum = 0;
        for (size_t i = 0; i < n; i++) {
            int x;
            if (read(fd[0], &x, sizeof(x)) != sizeof(x)) {
                perror("read element");
                return 1;
            }
            sum += x;
        }
        close(fd[0]);
        printf("Sum = %lld\n", sum);
        return 0;
    } else {
        // Батько: надсилає спочатку кількість, потім елементи
        close(fd[0]); // не читаємо
        if (write(fd[1], &count, sizeof(count)) != sizeof(count)) {
            perror("write count");
        }
        for (size_t i = 0; i < count; i++) {
            if (write(fd[1], &nums[i], sizeof(nums[i])) != sizeof(nums[i])) {
                perror("write element");
                break;
            }
        }
        close(fd[1]);
        wait(NULL);
        return 0;
    }
}
