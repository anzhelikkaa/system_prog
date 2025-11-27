#include <stdio.h>
#include <stdlib.h>

int main() {
    float *arr = (float*)calloc(5, sizeof(float));

    if (arr == NULL) {
        return 1;
    }

    printf("Calloc array (should be zeros): ");
    for (int i = 0; i < 5; i++) {
        printf("%.1f ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}