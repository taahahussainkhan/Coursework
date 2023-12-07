#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    int* arr;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    arr = (int*) malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Error allocating memory for array.\n");
        return 1;
    }

    printf("Enter the array elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int min1, min2;

    if (size < 2) {
        printf("Error: Array size must be greater than or equal to 2.\n");
        return 1;
    }

    min1 = min2 = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] < min2 && arr[i] != min1) {
            min2 = arr[i];
        }
    }

    printf("The second smallest element in the array is: %d\n", min2);

    free(arr);

    return 0;
}