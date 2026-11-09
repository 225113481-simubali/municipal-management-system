#include <stdio.h>
#include "budget.h"
#include "utilities.h"

#define TEXT_FILE "data/budgets.txt"

static double totalRevenue = 0;
static double totalExpenses = 0;

void addBudget(void)
{
    double revenue = readDouble("Enter revenue: ");
    double expenses = readDouble("Enter expenses: ");

    totalRevenue = totalRevenue + revenue;
    totalExpenses = totalExpenses + expenses;

    printf("Budget added.\n");
}

double calculateBudgetBalance(void)
{
    return totalRevenue - totalExpenses;
}

double getTotalRevenue(void)
{
    return totalRevenue;
}

double getTotalExpenses(void)
{
    return totalExpenses;
}

int saveBudgetText(void)
{
    FILE *fp = fopen(TEXT_FILE, "w");

    if (fp == NULL)
    {
        perror(TEXT_FILE);
        return -1;
    }

    fprintf(fp, "%.2f|%.2f\n", totalRevenue, totalExpenses);

    fclose(fp);
    return 1;
}

int loadBudgetText(void)
{
    FILE *fp = fopen(TEXT_FILE, "r");
    char line[200];
    double revenue;
    double expenses;

    if (fp == NULL)
    {
        return -1;
    }

    if (fgets(line, sizeof(line), fp) != NULL && sscanf(line, "%lf|%lf", &revenue, &expenses) == 2)
    {
        totalRevenue = revenue;
        totalExpenses = expenses;
        fclose(fp);
        return 1;
    }

    fclose(fp);
    return 0;
}