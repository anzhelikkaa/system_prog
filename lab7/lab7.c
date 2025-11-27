#include <stdio.h>
#include <pthread.h>

#define ITERATIONS 1000000

long long counter = 0;
pthread_mutex_t lock;

void* increment_counter(void* arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        pthread_mutex_lock(&lock);
        
        counter++; 
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Mutex init has failed\n");
        return 1;
    }

    pthread_create(&t1, NULL, increment_counter, NULL);
    pthread_create(&t2, NULL, increment_counter, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);

    printf("Final counter value: %lld (Expected: %d)\n", counter, ITERATIONS * 2);
    return 0;
}