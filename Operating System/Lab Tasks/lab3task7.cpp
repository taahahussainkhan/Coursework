#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    int age;
    float pay;
};

int main() {
    struct Employee emp;

    printf("Enter employee ID: ");
    scanf("%d", &emp.id);

    printf("Enter employee name: ");
    scanf("%s", emp.name);

    printf("Enter employee age: ");
    scanf("%d", &emp.age);

    printf("Enter employee pay: ");
    scanf("%f", &emp.pay);

    printf("\nEmployee Information:\n");
    printf("ID: %d\n", emp.id);
    printf("Name: %s\n", emp.name);
    printf("Age: %d\n", emp.age);
    printf("Pay: %.2f\n", emp.pay);

    return 0;
}