#include <stdio.h>
#include "employees.h"
#include "records.h"
#include "utilities.h"

#define FILE_NAME "data/employees.dat"

static Employee employees[MAX_RECORDS];
static int employeeCount = 0;

void addEmployee(void)
{
    if (employeeCount >= MAX_RECORDS)
    {
        printf("The employee list is full.\n");
        return;
    }

    employees[employeeCount].id = readInt("Enter employee ID: ");
    readText("Enter name: ", employees[employeeCount].name, 30);
    readText("Enter department: ", employees[employeeCount].department, 20);
    employees[employeeCount].salary = readDouble("Enter salary: ");
    employeeCount++;

    printf("Employee added.\n");
}

void displayEmployees(void)
{
    if (employeeCount == 0)
    {
        printf("No employees have been added yet.\n");
        return;
    }

    printf("\n%-6s %-20s %-15s %12s\n", "ID", "Name", "Department", "Salary");
    for (int i = 0; i < employeeCount; i++)
    {
        printf("%-6d %-20s %-15s %12.2f\n",
               employees[i].id, employees[i].name,
               employees[i].department, employees[i].salary);
    }
}

void searchEmployee(void)
{
    int id = readInt("Enter employee ID to search: ");

    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].id == id)
        {
            printf("Employee found.\n");
            printf("ID: %d | Name: %s | Department: %s | Salary: %.2f\n",
                   employees[i].id, employees[i].name,
                   employees[i].department, employees[i].salary);
            return;
        }
    }

    printf("Employee not found.\n");
}

double calculatePayrollTotal(void)
{
    double total = 0;

    for (int i = 0; i < employeeCount; i++)
    {
        total = total + employees[i].salary;
    }

    return total;
}

int getEmployeeCount(void)
{
    return employeeCount;
}

void updateSalary(Employee *e, double newSalary)
{
    e->salary = newSalary;
}

Employee *findEmployee(Employee list[], int n, int id)
{
    for (int i = 0; i < n; i++)
    {
        if (list[i].id == id)
        {
            return &list[i];
        }
    }

    return NULL;
}

void updateEmployeeSalary(void)
{
    int id = readInt("Enter employee ID to update: ");
    Employee *found = findEmployee(employees, employeeCount, id);
    double newSalary;

    if (found == NULL)
    {
        printf("Employee with ID %d was not found.\n", id);
        return;
    }

    newSalary = readDouble("Enter new salary: ");
    updateSalary(found, newSalary);

    printf("Salary updated.\n");
    printf("ID: %d | Name: %s | Department: %s | Salary: %.2f\n",
           found->id, found->name, found->department, found->salary);
}

int saveEmployeesBinary(void)
{
    FILE *fp = fopen(FILE_NAME, "wb");
    size_t written;

    if (fp == NULL)
    {
        perror(FILE_NAME);
        return -1;
    }

    written = fwrite(employees, sizeof employees[0], employeeCount, fp);
    fclose(fp);

    if ((int)written != employeeCount)
    {
        return -1;
    }

    return employeeCount;
}

int loadEmployeesBinary(void)
{
    FILE *fp = fopen(FILE_NAME, "rb");
    size_t loaded;

    if (fp == NULL)
    {
        return -1;
    }

    loaded = fread(employees, sizeof employees[0], MAX_RECORDS, fp);
    fclose(fp);

    employeeCount = (int)loaded;
    return employeeCount;
}