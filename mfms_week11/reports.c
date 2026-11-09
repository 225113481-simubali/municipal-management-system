#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"

void employeeReport(void)
{
    int count = getEmployeeCount();
    double total = calculatePayrollTotal();

    printf("\n--- EMPLOYEE REPORT ---\n");
    printf("Number of employees: %d\n", count);
    printf("Total payroll: %.2f\n", total);

    if (count > 0)
    {
        printf("Average salary: %.2f\n", total / count);
    }
}

void budgetReport(void)
{
    double allocated = getTotalAllocated();
    double spent = getTotalSpent();
    double balance = allocated - spent;

    printf("\n--- BUDGET REPORT ---\n");
    printf("Total allocated: %.2f\n", allocated);
    printf("Total spent: %.2f\n", spent);
    printf("Balance: %.2f\n", balance);

    if (balance > 0)
    {
        printf("SURPLUS\n");
    }
    else if (balance < 0)
    {
        printf("DEFICIT\n");
    }
    else
    {
        printf("BALANCED\n");
    }
}