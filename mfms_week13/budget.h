#ifndef BUDGET_H
#define BUDGET_H

void addBudget(void);
void displayBudgets(void);
double getTotalAllocated(void);
double getTotalSpent(void);
int saveBudgetsBinary(void);
int loadBudgetsBinary(void);

#endif