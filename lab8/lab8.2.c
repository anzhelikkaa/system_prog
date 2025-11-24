#include <stdio.h>
#include <stdlib.h>

int main() {
    // 1. Виділяємо для 3 елементів
    int *arr = (int*)malloc(3 * sizeof(int));
    
    // Заповнюємо перші 3
    for(int i = 0; i < 3; i++) arr[i] = (i + 1) * 10;

    // 2. Розширюємо до 6 елементів
    // Важливо: realloc повертає новий вказівник
    int *temp = (int*)realloc(arr, 6 * sizeof(int));
    
    if (temp != NULL) {
        arr = temp; // Оновлюємо вказівник
    } else {
        free(arr); // Якщо не вдалося розширити, очищаємо старий і виходимо
        return 1;
    }

    // Дозаповнюємо нові комірки (індекси 3, 4, 5)
    for(int i = 3; i < 6; i++) arr[i] = (i + 1) * 10;

    printf("Realloc array: ");
    for(int i = 0; i < 6; i++) printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}