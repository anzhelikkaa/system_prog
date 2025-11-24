#include <stdio.h>
#include <stdlib.h>

int main() {
    // Виділення пам'яті: 10 * 4 байти (зазвичай) = 40 байт
    int *arr = (int*)malloc(10 * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Заповнення та виведення
    printf("Malloc array: ");
    for (int i = 0; i < 10; i++) {
        arr[i] = i + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Звільнення пам'яті
    free(arr);
    return 0;
}