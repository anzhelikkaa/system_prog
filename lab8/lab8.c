#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int*)malloc(10 * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Malloc array: ");
    for (int i = 0; i < 10; i++) {
        arr[i] = i + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}