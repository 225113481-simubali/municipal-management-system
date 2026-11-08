#include <stdio.h>
#include "budget.h"
#include "utilities.h"

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