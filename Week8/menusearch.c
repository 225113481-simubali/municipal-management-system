#include <stdio.h>

void displayMenu();
int searchEmployee(int id, int ids[], int size);

int main()
{
    int choice;
    int id;
    int position;
    int employeeIDs[] = {101, 102, 103, 104, 105};

    displayMenu();
    scanf("%d", &choice);

    printf("You chose option %d\n", choice);

    printf("\nEnter employee ID: ");
    scanf("%d", &id);

    position = searchEmployee(id, employeeIDs, 5);

    if (position == -1)
    {
        printf("Employee not found.\n");
    }
    else
    {
        printf("Employee found at position %d.\n", position);
    }

    return 0;
}

void displayMenu()
{
    printf("\n");
    printf("==================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("==================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
}

int searchEmployee(int id, int ids[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (ids[i] == id)
        {
            return i;
        }
    }

    return -1;
}