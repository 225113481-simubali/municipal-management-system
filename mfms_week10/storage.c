#include <stdio.h>
#include "storage.h"
#include "employees.h"
#include "suppliers.h"
#include "assets.h"
#include "budget.h"

static void showSaved(const char *name, int result)
{
    if (result < 0)
    {
        printf("%s: could not be saved.\n", name);
    }
    else
    {
        printf("%s: %d record(s) saved.\n", name, result);
    }
}

static void showLoaded(const char *name, int result)
{
    if (result < 0)
    {
        printf("%s: no saved file found.\n", name);
    }
    else
    {
        printf("%s: %d record(s) loaded.\n", name, result);
    }
}

void saveAllData(void)
{
    showSaved("Employees", saveEmployeesText());
    showSaved("Suppliers", saveSuppliersText());
    showSaved("Assets", saveAssetsText());
    showSaved("Budgets", saveBudgetText());
}

void loadAllData(void)
{
    showLoaded("Employees", loadEmployeesText());
    showLoaded("Suppliers", loadSuppliersText());
    showLoaded("Assets", loadAssetsText());
    showLoaded("Budgets", loadBudgetText());
}

void saveBinaryData(void)
{
    showSaved("Employees (binary)", saveEmployeesBinary());
}

void loadBinaryData(void)
{
    showLoaded("Employees (binary)", loadEmployeesBinary());
}