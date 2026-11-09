#include <stdio.h>
#include "storage.h"
#include "employees.h"
#include "suppliers.h"
#include "assets.h"
#include "budget.h"
#include "projects.h"

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
    showSaved("Employees", saveEmployeesBinary());
    showSaved("Suppliers", saveSuppliersBinary());
    showSaved("Assets", saveAssetsBinary());
    showSaved("Budgets", saveBudgetsBinary());
    showSaved("Projects", saveProjectsBinary());
}

void loadAllData(void)
{
    showLoaded("Employees", loadEmployeesBinary());
    showLoaded("Suppliers", loadSuppliersBinary());
    showLoaded("Assets", loadAssetsBinary());
    showLoaded("Budgets", loadBudgetsBinary());
    showLoaded("Projects", loadProjectsBinary());
}