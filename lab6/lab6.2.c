#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* calculate_factorial(void* arg) {
    int n = *(int*)arg;
    unsigned long long* result = malloc(sizeof(unsigned long long)); 
    *result = 1;

    for (int i = 1; i <= n; i++) {
        *result *= i;
    }
    
    return (void*)result;
}

int main() {
    pthread_t thread;
    int number = 10;
    void* thread_result;

    printf("Main: Calculating factorial of %d...\n", number);

    pthread_create(&thread, NULL, calculate_factorial, &number);

    pthread_join(thread, &thread_result);

    unsigned long long* fact = (unsigned long long*)thread_result;
    printf("Main: Factorial result is %llu\n", *fact);

    free(fact);
    return 0;
}