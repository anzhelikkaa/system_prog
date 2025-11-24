#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t semaphore; // Семафор

void* access_resource(void* arg) {
    int id = *(int*)arg;
    
    printf("Thread %d waiting...\n", id);
    
    // sem_wait: зменшує лічильник. Якщо 0 — блокує потік.
    sem_wait(&semaphore);
    
    printf("Thread %d entered the restricted area.\n", id);
    sleep(2); // Імітація тривалої роботи
    
    printf("Thread %d leaving.\n", id);
    
    // sem_post: збільшує лічильник, дозволяючи іншому потоку зайти.
    sem_post(&semaphore);
    
    return NULL;
}

int main() {
    pthread_t threads[5];
    int ids[5] = {1, 2, 3, 4, 5};

    // Ініціалізація: 0 - для потоків одного процесу, 2 - початкове значення (дозволено 2 потоки одночасно)
    sem_init(&semaphore, 0, 2);

    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, access_resource, &ids[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&semaphore);
    return 0;
}