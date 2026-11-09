#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "utilities.h"

#define MAX_EMPLOYEES 100
#define TEXT_FILE "data/employees.txt"
#define BINARY_FILE "data/employees.dat"

typedef struct {
    int id;
    char name[50];
    double salary;
} Employee;

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

int saveEmployeesText(void)
{
    FILE *fp = fopen(TEXT_FILE, "w");

    if (fp == NULL)
    {
        perror(TEXT_FILE);
        return -1;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%d|%s|%.2f\n", ids[i], names[i], salaries[i]);
    }

    fclose(fp);
    return count;
}

int loadEmployeesText(void)
{
    FILE *fp = fopen(TEXT_FILE, "r");
    char line[200];
    char name[50];
    int id;
    double salary;
    int loaded = 0;

    if (fp == NULL)
    {
        return -1;
    }

    while (loaded < MAX_EMPLOYEES && fgets(line, sizeof(line), fp) != NULL)
    {
        if (sscanf(line, "%d|%49[^|]|%lf", &id, name, &salary) == 3)
        {
            ids[loaded] = id;
            strcpy(names[loaded], name);
            salaries[loaded] = salary;
            loaded++;
        }
    }

    fclose(fp);
    count = loaded;
    return loaded;
}

int saveEmployeesBinary(void)
{
    FILE *fp = fopen(BINARY_FILE, "wb");
    Employee e;

    if (fp == NULL)
    {
        perror(BINARY_FILE);
        return -1;
    }

    for (int i = 0; i < count; i++)
    {
        memset(&e, 0, sizeof e);
        e.id = ids[i];
        strcpy(e.name, names[i]);
        e.salary = salaries[i];

        if (fwrite(&e, sizeof e, 1, fp) != 1)
        {
            perror("Error writing employee");
            fclose(fp);
            return -1;
        }
    }

    fclose(fp);
    return count;
}

int loadEmployeesBinary(void)
{
    FILE *fp = fopen(BINARY_FILE, "rb");
    Employee e;
    int loaded = 0;

    if (fp == NULL)
    {
        return -1;
    }

    while (loaded < MAX_EMPLOYEES && fread(&e, sizeof e, 1, fp) == 1)
    {
        ids[loaded] = e.id;
        strncpy(names[loaded], e.name, 49);
        names[loaded][49] = '\0';
        salaries[loaded] = e.salary;
        loaded++;
    }

    fclose(fp);
    count = loaded;
    return loaded;
}