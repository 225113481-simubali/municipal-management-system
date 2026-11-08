#include <stdio.h>
#include "employees.h"
#include "utilities.h"

#define MAX_EMPLOYEES 100

static int ids[MAX_EMPLOYEES];
static char names[MAX_EMPLOYEES][50];
static double salaries[MAX_EMPLOYEES];
static int count = 0;

void addEmployee(void)
{
    if (count >= MAX_EMPLOYEES)
    {
        printf("The employee list is full.\n");
        return;
    }

    ids[count] = readInt("Enter employee ID: ");
    readText("Enter employee name: ", names[count], 50);
    salaries[count] = readDouble("Enter salary: ");
    count++;

    printf("Employee added.\n");
}

void listEmployees(void)
{
    if (count == 0)
    {
        printf("No employees have been added yet.\n");
        return;
    }

    printf("\n--- EMPLOYEES ---\n");
    for (int i = 0; i < count; i++)
    {
        printf("ID: %d | Name: %s | Salary: %.2f\n", ids[i], names[i], salaries[i]);
    }
}

void searchEmployee(void)
{
    int id = readInt("Enter employee ID to search: ");

    for (int i = 0; i < count; i++)
    {
        if (ids[i] == id)
        {
            printf("Employee found.\n");
            printf("ID: %d | Name: %s | Salary: %.2f\n", ids[i], names[i], salaries[i]);
            return;
        }
    }

    printf("Employee not found.\n");
}

double calculatePayrollTotal(void)
{
    double total = 0;

    for (int i = 0; i < count; i++)
    {
        total = total + salaries[i];
    }

    return total;
}

int getEmployeeCount(void)
{
    return count;
}