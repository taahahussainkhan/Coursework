#include <stdio.h>

int is_valid_triangle(float a, float b, float c) {
    if (a + b <= c || a + c <= b || b + c <= a) {
        return 0;
    } else {
        return 1;
    }
}

char* triangle_type(float a, float b, float c) {
    if (a == b && b == c) {
        return "Equilateral Triangle";
    } else if (a == b || b == c || a == c) {
        return "Isosceles Triangle";
    } else {
        return "Scalene Triangle";
    }
}

int main() {
    float side_a, side_b, side_c;

    printf("Enter the length of the first side of the triangle: ");
    scanf("%f", &side_a);

    printf("Enter the length of the second side of the triangle: ");
    scanf("%f", &side_b);

    printf("Enter the length of the third side of the triangle: ");
    scanf("%f", &side_c);

    if (is_valid_triangle(side_a, side_b, side_c)) {
        char* type = triangle_type(side_a, side_b, side_c);
        printf("The triangle is a %s.\n", type);
    } else {
        printf("The sides do not form a valid triangle.\n");
    }

    return 0;
}