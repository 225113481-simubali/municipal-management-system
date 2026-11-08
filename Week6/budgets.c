#include <stdio.h>

int main() {

    float budgets[10];
    float total = 0;
    float average;
    float temp;

    for (int i = 0; i < 10; i++) {
        printf("Enter budget for department %d: ", i + 1);
        scanf("%f", &budgets[i]);
    }

    printf("\nDepartment Budgets\n");
    for (int i = 0; i < 10; i++) {
        printf("Department %d: %.2f\n", i + 1, budgets[i]);
    }

    for (int i = 0; i < 10; i++) {
        total = total + budgets[i];
    }
    average = total / 10;

    printf("\nTotal budget: %.2f\n", total);
    printf("Average budget: %.2f\n", average);

    for (int i = 0; i < 10 - 1; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
            if (budgets[j] > budgets[j + 1]) {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    printf("\nBudgets sorted from lowest to highest\n");
    for (int i = 0; i < 10; i++) {
        printf("%.2f\n", budgets[i]);
    }

    return 0;
}