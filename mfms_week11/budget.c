#include <stdio.h>
#include "budget.h"
#include "records.h"
#include "utilities.h"

#define FILE_NAME "data/budgets.dat"

static Budget budgets[MAX_RECORDS];
static int budgetCount = 0;

void addBudget(void)
{
    if (budgetCount >= MAX_RECORDS)
    {
        printf("The budget list is full.\n");
        return;
    }

    readText("Enter department: ", budgets[budgetCount].department, 20);
    budgets[budgetCount].allocated = readDouble("Enter allocated amount: ");
    budgets[budgetCount].spent = readDouble("Enter amount spent: ");
    budgetCount++;

    printf("Budget added.\n");
}

void displayBudgets(void)
{
    if (budgetCount == 0)
    {
        printf("No budgets have been added yet.\n");
        return;
    }

    printf("\n%-20s %14s %14s %14s\n", "Department", "Allocated", "Spent", "Balance");
    for (int i = 0; i < budgetCount; i++)
    {
        printf("%-20s %14.2f %14.2f %14.2f\n",
               budgets[i].department, budgets[i].allocated, budgets[i].spent,
               budgets[i].allocated - budgets[i].spent);
    }
}

double getTotalAllocated(void)
{
    double total = 0;

    for (int i = 0; i < budgetCount; i++)
    {
        total = total + budgets[i].allocated;
    }

    return total;
}

double getTotalSpent(void)
{
    double total = 0;

    for (int i = 0; i < budgetCount; i++)
    {
        total = total + budgets[i].spent;
    }

    return total;
}

int saveBudgetsBinary(void)
{
    FILE *fp = fopen(FILE_NAME, "wb");
    size_t written;

    if (fp == NULL)
    {
        perror(FILE_NAME);
        return -1;
    }

    written = fwrite(budgets, sizeof budgets[0], budgetCount, fp);
    fclose(fp);

    if ((int)written != budgetCount)
    {
        return -1;
    }

    return budgetCount;
}

int loadBudgetsBinary(void)
{
    FILE *fp = fopen(FILE_NAME, "rb");
    size_t loaded;

    if (fp == NULL)
    {
        return -1;
    }

    loaded = fread(budgets, sizeof budgets[0], MAX_RECORDS, fp);
    fclose(fp);

    budgetCount = (int)loaded;
    return budgetCount;
}