#include <stdio.h>
#include <pthread.h>

#define ITERATIONS 1000000

long long counter = 0;
pthread_mutex_t lock; // Оголошення м'ютекса

void* increment_counter(void* arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        // 1. Захоплення м'ютекса (вхід у критичну секцію)
        pthread_mutex_lock(&lock);
        
        counter++; // Критична секція
        
        // 2. Звільнення м'ютекса (вихід з критичної секції)
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Ініціалізація м'ютекса
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Mutex init has failed\n");
        return 1;
    }

    pthread_create(&t1, NULL, increment_counter, NULL);
    pthread_create(&t2, NULL, increment_counter, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Знищення м'ютекса після використання
    pthread_mutex_destroy(&lock);

    printf("Final counter value: %lld (Expected: %d)\n", counter, ITERATIONS * 2);
    return 0;
}