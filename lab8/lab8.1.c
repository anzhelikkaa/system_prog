#include <stdio.h>
#include <stdlib.h>

int main() {
    // Виділяємо пам'ять для 5 float
    float *arr = (float*)calloc(5, sizeof(float));

    if (arr == NULL) {
        return 1;
    }

    printf("Calloc array (should be zeros): ");
    for (int i = 0; i < 5; i++) {
        // Виводимо з точністю 1 знак після коми
        printf("%.1f ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}