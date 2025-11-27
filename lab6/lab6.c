#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void* arg) {
    printf("Hello from thread\n");
    return NULL;
}

int main() {
    pthread_t thread;

    if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
        perror("Failed to create thread");
        return 1;
    }

    printf("Hello from main\n");

    pthread_join(thread, NULL);

    return 0;
}