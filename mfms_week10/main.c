#include <stdio.h>
#include "employees.h"
#include "suppliers.h"
#include "assets.h"
#include "budget.h"
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
    printf("2. List Employees\n");
    printf("3. Search Employee\n");
    printf("4. Add Supplier\n");
    printf("5. List Suppliers\n");
    printf("6. Add Asset\n");
    printf("7. List Assets\n");
    printf("8. Add Budget\n");
    printf("9. Employee Report\n");
    printf("10. Budget Report\n");
    printf("11. Save Data\n");
    printf("12. Load Data\n");
    printf("13. Save Employees (Binary)\n");
    printf("14. Load Employees (Binary)\n");
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
                addSupplier();
                break;

            case 5:
                listSuppliers();
                pauseScreen();
                break;

            case 6:
                addAsset();
                break;

            case 7:
                listAssets();
                pauseScreen();
                break;

            case 8:
                addBudget();
                break;

            case 9:
                employeeReport();
                pauseScreen();
                break;

            case 10:
                budgetReport();
                pauseScreen();
                break;

            case 11:
                saveAllData();
                break;

            case 12:
                loadAllData();
                break;

            case 13:
                saveBinaryData();
                break;

            case 14:
                loadBinaryData();
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