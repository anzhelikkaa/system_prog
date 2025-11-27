#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int*)malloc(3 * sizeof(int));
    
    for(int i = 0; i < 3; i++) arr[i] = (i + 1) * 10;

    int *temp = (int*)realloc(arr, 6 * sizeof(int));
    
    if (temp != NULL) {
        arr = temp;
    } else {
        free(arr);
        return 1;
    }

    for(int i = 3; i < 6; i++) arr[i] = (i + 1) * 10;

    printf("Realloc array: ");
    for(int i = 0; i < 6; i++) printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}