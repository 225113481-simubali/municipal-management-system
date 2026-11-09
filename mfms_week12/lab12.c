#include <stdio.h>

#define MAX_EMPLOYEES 5

typedef struct {
    int    id;
    char   name[30];
    double salary;
} Employee;

void swapWrong(double a, double b)
{
    double temp = a;
    a = b;
    b = temp;
}

void swapSalaries(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

void displaySalaries(const double salaries[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("  Employee %d: N$%.2f\n", i + 1, salaries[i]);
    }
}

double findHighest(const double salaries[], int n)
{
    double highest = salaries[0];

    for (int i = 1; i < n; i++)
    {
        if (salaries[i] > highest)
        {
            highest = salaries[i];
        }
    }

    return highest;
}

double calculateAverage(const double salaries[], int n)
{
    double total = 0.0;

    for (int i = 0; i < n; i++)
    {
        total = total + salaries[i];
    }

    return total / n;
}

void giveRaise(double salaries[], int n, double percent)
{
    for (int i = 0; i < n; i++)
    {
        salaries[i] = salaries[i] * (1 + percent / 100);
    }
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

int main(void)
{
    int age = 25;
    int *p = &age;
    double salaryA = 18500.50;
    double salaryB = 21000.75;
    double salaries[4] = {15000.00, 18500.50, 21000.75, 17200.00};
    Employee staff[MAX_EMPLOYEES] = {
        {1001, "Maria", 18500.50},
        {1002, "Simon", 17200.00},
        {1003, "Anna", 21000.75}
    };
    int count = 3;
    Employee *found;

    printf("PART A - POINTERS\n");
    printf("Value of age: %d\n", age);
    printf("Address of age: %p\n", (void *)&age);
    printf("Value of p (an address): %p\n", (void *)p);
    printf("Value at *p: %d\n", *p);
    *p = 30;
    printf("After *p = 30, age = %d\n", age);

    printf("\nPART B - SWAP SALARIES\n");
    printf("Before: A = %.2f, B = %.2f\n", salaryA, salaryB);
    swapWrong(salaryA, salaryB);
    printf("After swapWrong: A = %.2f, B = %.2f\n", salaryA, salaryB);
    swapSalaries(&salaryA, &salaryB);
    printf("After swapSalaries: A = %.2f, B = %.2f\n", salaryA, salaryB);

    printf("\nPART C - ARRAYS AND FUNCTIONS\n");
    printf("Salaries before the raise:\n");
    displaySalaries(salaries, 4);
    printf("Highest: N$%.2f\n", findHighest(salaries, 4));
    printf("Average: N$%.2f\n", calculateAverage(salaries, 4));
    giveRaise(salaries, 4, 10.0);
    printf("Salaries after a 10%% raise:\n");
    displaySalaries(salaries, 4);
    printf("Average after the raise: N$%.2f\n", calculateAverage(salaries, 4));

    printf("\nPART D - MODIFY EMPLOYEE RECORDS\n");
    found = findEmployee(staff, count, 1002);
    if (found != NULL)
    {
        updateSalary(found, 19000.00);
        printf("%s now earns N$%.2f\n", found->name, found->salary);
        updateSalary(found, 20000.00);
        printf("%s now earns N$%.2f\n", found->name, found->salary);
    }

    found = findEmployee(staff, count, 9999);
    if (found == NULL)
    {
        printf("Employee 9999 was not found.\n");
    }

    return 0;
}