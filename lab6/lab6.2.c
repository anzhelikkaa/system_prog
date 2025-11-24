#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Функція для обчислення факторіала
void* calculate_factorial(void* arg) {
    int n = *(int*)arg;
    // Виділяємо пам'ять під результат, бо локальна змінна знищиться після виходу з функції
    unsigned long long* result = malloc(sizeof(unsigned long long)); 
    *result = 1;

    for (int i = 1; i <= n; i++) {
        *result *= i;
    }
    
    return (void*)result; // Повертаємо вказівник
}

int main() {
    pthread_t thread;
    int number = 10; // Число для факторіала
    void* thread_result;

    printf("Main: Calculating factorial of %d...\n", number);

    pthread_create(&thread, NULL, calculate_factorial, &number);

    // Другий аргумент join отримує те, що повернув потік
    pthread_join(thread, &thread_result);

    unsigned long long* fact = (unsigned long long*)thread_result;
    printf("Main: Factorial result is %llu\n", *fact);

    free(fact); // Не забуваємо звільнити пам'ять
    return 0;
}