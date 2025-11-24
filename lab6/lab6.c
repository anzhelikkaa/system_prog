#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // Для sleep (опціонально)

// Функція потоку
void* thread_function(void* arg) {
    printf("Hello from thread\n");
    return NULL;
}

int main() {
    pthread_t thread; // Ідентифікатор потоку

    // 1. Створення потоку
    if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
        perror("Failed to create thread");
        return 1;
    }

    // Повідомлення від головного потоку
    printf("Hello from main\n");

    // 2. Очікування завершення потоку
    pthread_join(thread, NULL);

    return 0;
}