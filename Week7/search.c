#include <stdio.h>
#include <string.h>

int main()
{
    char supplier1[] = "ABC Office Supplies";
    char supplier2[] = "Namibia Stationery";
    char searchName[100];

    printf("Enter supplier name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    if (strcmp(supplier1, searchName) == 0 || strcmp(supplier2, searchName) == 0)
    {
        printf("\nSupplier found.\n");
    }
    else
    {
        printf("\nSupplier not found.\n");
    }

    return 0;
}