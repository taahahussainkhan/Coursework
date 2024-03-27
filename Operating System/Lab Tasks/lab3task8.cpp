#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee {
    char id[10];
    char name[50];
    char gender;
    char jobPosition[50];
    int experience;
    float pay;
} Employee;

Employee employeeList[100];
int count = 0;

void addRecord() {
    if (count >= 100) {
        printf("Employee list is full.\n");
        return;
    }

    Employee newEmployee;

    printf("Enter employee ID: ");
    scanf("%s", newEmployee.id);

    printf("Enter employee name without spaces: ");
    scanf("%s", newEmployee.name);

    printf("Enter employee gender (m/f): ");
    scanf(" %c", &newEmployee.gender);

    printf("Enter employee job position without spaces (internee/developer): ");
    scanf("%s", newEmployee.jobPosition);

    printf("Enter employee experience in years: ");
    scanf("%d", &newEmployee.experience);

    printf("Enter employee pay: ");
    scanf("%f", &newEmployee.pay);

    employeeList[count] = newEmployee;
    count++;

    printf("Employee record added successfully.\n");
}

void searchRecordByID() {
    char id[10];
    printf("Enter employee ID to search: ");
    scanf("%s", id);

    int index = -1;
    for (int i = 0; i < count; i++) {
        if (strcmp(employeeList[i].id, id) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Employee with ID %s not found.\n", id);
    } else {
        printf("Employee record found:\n");
        printf("ID: %s\n", employeeList[index].id);
        printf("Name: %s\n", employeeList[index].name);
        printf("Gender: %c\n", employeeList[index].gender);
        printf("Job Position: %s\n", employeeList[index].jobPosition);
        printf("Experience: %d years\n", employeeList[index].experience);
        printf("Pay: %.2f\n", employeeList[index].pay);
    }
}

void showAllRecords() {
    if (count == 0) {
        printf("Employee list is empty.\n");
        return;
    }

    printf("List of all employees:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %s\n", employeeList[i].id);
        printf("Name: %s\n", employeeList[i].name);
        printf("Gender: %c\n", employeeList[index].gender);
        printf("Job Position: %s\n", employeeList[index].jobPosition);
        printf("Experience: %d years\n", employeeList[index].experience);
        printf("Pay: %.2f\n\n", employeeList[index].pay);
    }
}

void showBelowBasicPay() {
    int basicPay = 20000;

    printf("Employees having pay less than basic pay (%d):\n", basicPay);

    for (int i = 0; i < count; i++) {
        if (employeeList[i].pay < basicPay) {
            printf("ID: %s\n", employeeList[i].id);
            printf("Name: %s\n", employeeList[index].name);
            printf("Job Position: %s\n", employeeList[index].jobPosition);
            printf("Pay: %.2f\n\n", employeeList[index].pay);
        }
    }
}

void saveAndExit() {
    printf("Saving employee data to file...\n");

    FILE *fp = fopen("task1.txt", "w");

    if (fp == NULL) {
        printf("Error opening file for writing.\n");
int main() {
    int option;

    while (1) {
        printf("================== MENU ===================\n");
        printf("1. Add a record\n");
        printf("2. Search a record by ID\n");
        printf("3. Show all records\n");
        printf("4. Show employees having pay less than basic pay (20000)\n");
        printf("5. Save and exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addRecord();
                break;
            case 2:
                searchRecordByID();
                break;
            case 3:
                showAllRecords();
                break;
            case 4:
                showBelowBasicPay();
                break;
            case 5:
                saveAndExit();
                exit(0);
            default:
                printf("Invalid option. Please choose from the given menu.\n");
        }
    }

    return 0;
}