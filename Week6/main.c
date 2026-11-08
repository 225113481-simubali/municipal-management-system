#include <stdio.h>

int main() {

    float salaries[50];
    float total = 0;
    float average;
    float highest;
    float lowest;
    float search;
    int found = 0;

    for (int i = 0; i < 50; i++) {
        printf("Enter salary %d: ", i + 1);
        scanf("%f", &salaries[i]);
    }

    printf("\nEmployee Salaries\n");
    for (int i = 0; i < 50; i++) {
        printf("%d: %.2f\n", i + 1, salaries[i]);
    }

    highest = salaries[0];
    lowest = salaries[0];

    for (int i = 0; i < 50; i++) {
        total = total + salaries[i];

        if (salaries[i] > highest) {
            highest = salaries[i];
        }
        if (salaries[i] < lowest) {
            lowest = salaries[i];
        }
    }

    average = total / 50;

    printf("\nAverage salary: %.2f\n", average);
    printf("Highest salary: %.2f\n", highest);
    printf("Lowest salary: %.2f\n", lowest);

    printf("\nEnter a salary to search for: ");
    scanf("%f", &search);

    for (int i = 0; i < 50; i++) {
        if (salaries[i] == search) {
            found = 1;
            printf("Salary found at position %d\n", i);
            break;
        }
    }

    if (!found) {
        printf("Salary not found.\n");
    }

    return 0;
}