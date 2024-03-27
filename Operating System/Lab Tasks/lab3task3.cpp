#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}

int main() {
    int arr[20];
    int num;
    int i = 0;

    printf("Enter the integers (terminate with -99):\n");
    do {
        scanf("%d", &num);
        if (num != -99) {
            arr[i] = num;
            i++;
        }
    } while (num != -99 && i < 20);

    printf("The entered sequence is:\n");
    for (int j = 0; j < i; j++) {
        printf("%d ", arr[j]);
    }

    bubbleSort(arr, i);

    printf("\nUpdated sequence is:\n");
    for (int j = 0; j < i; j++) {
        printf("%d ", arr[j]);
    }

    return 0;
}