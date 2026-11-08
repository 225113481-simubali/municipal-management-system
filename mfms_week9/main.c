#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "reports.h"
#include "utilities.h"

void displayMainMenu(void)
{
    printf("\n");
    printf("==================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("==================================\n");
    printf("1. Add Employee\n");
    printf("2. List Employees\n");
    printf("3. Search Employee\n");
    printf("4. Add Budget\n");
    printf("5. Employee Report\n");
    printf("6. Budget Report\n");
    printf("0. Exit\n");
}

int main(void)
{
    int choice;

    do
    {
        displayMainMenu();
        choice = readInt("Enter choice: ");

        switch (choice)
        {
            case 1:
                addEmployee();
                break;

            case 2:
                listEmployees();
                pauseScreen();
                break;

            case 3:
                searchEmployee();
                pauseScreen();
                break;

            case 4:
                addBudget();
                break;

            case 5:
                employeeReport();
                pauseScreen();
                break;

            case 6:
                budgetReport();
                pauseScreen();
                break;

            case 0:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 0);

    return 0;
}