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
    double balance = calculateBudgetBalance();

    printf("\n--- BUDGET REPORT ---\n");
    printf("Total revenue: %.2f\n", getTotalRevenue());
    printf("Total expenses: %.2f\n", getTotalExpenses());
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