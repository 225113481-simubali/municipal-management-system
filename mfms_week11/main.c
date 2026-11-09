#include <stdio.h>
#include "employees.h"
#include "suppliers.h"
#include "assets.h"
#include "budget.h"
#include "projects.h"
#include "reports.h"
#include "storage.h"
#include "utilities.h"

void displayMainMenu(void)
{
    printf("\n");
    printf("==================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("==================================\n");
    printf("1. Add Employee\n");
    printf("2. Display Employees\n");
    printf("3. Search Employee\n");
    printf("4. Add Supplier\n");
    printf("5. Display Suppliers\n");
    printf("6. Add Asset\n");
    printf("7. Display Assets\n");
    printf("8. Add Budget\n");
    printf("9. Display Budgets\n");
    printf("10. Add Project\n");
    printf("11. Display Projects\n");
    printf("12. Employee Report\n");
    printf("13. Budget Report\n");
    printf("14. Save Data\n");
    printf("15. Load Data\n");
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
                displayEmployees();
                pauseScreen();
                break;

            case 3:
                searchEmployee();
                pauseScreen();
                break;

            case 4:
                addSupplier();
                break;

            case 5:
                displaySuppliers();
                pauseScreen();
                break;

            case 6:
                addAsset();
                break;

            case 7:
                displayAssets();
                pauseScreen();
                break;

            case 8:
                addBudget();
                break;

            case 9:
                displayBudgets();
                pauseScreen();
                break;

            case 10:
                addProject();
                break;

            case 11:
                displayProjects();
                pauseScreen();
                break;

            case 12:
                employeeReport();
                pauseScreen();
                break;

            case 13:
                budgetReport();
                pauseScreen();
                break;

            case 14:
                saveAllData();
                break;

            case 15:
                loadAllData();
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