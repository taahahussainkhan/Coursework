#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error: Please provide two integers as command-line arguments.\n");
        return 1;
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    int product = num1 * num2;

    printf("The product of %d and %d is %d.\n", num1, num2, product);

    return 0;
}