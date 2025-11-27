#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t semaphore;

void* access_resource(void* arg) {
    int id = *(int*)arg;
    
    printf("Thread %d waiting...\n", id);
    
    sem_wait(&semaphore);
    
    printf("Thread %d entered the restricted area.\n", id);
    sleep(2);
    
    printf("Thread %d leaving.\n", id);
    
    sem_post(&semaphore);
    
    return NULL;
}

int main() {
    pthread_t threads[5];
    int ids[5] = {1, 2, 3, 4, 5};

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