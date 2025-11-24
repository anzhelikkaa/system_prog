#include <stdio.h>
#include <stdlib.h>  
#include <time.h>   

int sumArray(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];  
    }
    return sum;
}

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main() {
    int a = 10;
    int *p = &a;
    printf("a = %d, через p = %d, адреса a = %p\n\n", a, *p, (void*)p);

    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr; 
    printf("Елементи масиву через вказівник:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\nСума елементів масиву = %d\n\n", sumArray(arr, 5));

    int x = 7, y = 9;
    printf("До swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("   Після swap: x = %d, y = %d\n\n", x, y);

    int *dynArr = (int*)malloc(10 * sizeof(int));
    if (dynArr == NULL) {
        printf("Помилка виділення пам'яті!\n");
        return 1;
    }
    printf("Динамічний масив:\n");
    for (int i = 0; i < 10; i++) {
        dynArr[i] = i + 1;
        printf("%d ", dynArr[i]);
    }
    printf("\n");
    free(dynArr);

    return 0;
}
