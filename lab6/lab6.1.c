#include <stdio.h>
#include <pthread.h>

void* print_thread_num(void* arg) {
    int* num = (int*)arg; // Приведення void* назад до int*
    printf("Thread %d\n", *num);
    return NULL;
}

int main() {
    pthread_t threads[5];
    int thread_args[5]; // Масив для збереження аргументів

    for (int i = 0; i < 5; i++) {
        thread_args[i] = i + 1;
        // Створюємо потік і передаємо адресу аргументу
        if (pthread_create(&threads[i], NULL, print_thread_num, &thread_args[i]) != 0) {
            perror("Failed to create thread");
        }
    }

    // Чекаємо завершення всіх потоків
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}