#include <stdio.h>
#include <string.h>

int main()
{
    char names[5][100];
    char emails[5][100];
    char phones[5][30];
    char towns[5][50];
    char searchName[100];
    int found = 0;

    for (int i = 0; i < 5; i++)
    {
        printf("\nSupplier %d\n", i + 1);

        printf("Enter supplier name: ");
        fgets(names[i], sizeof(names[i]), stdin);
        names[i][strcspn(names[i], "\n")] = '\0';

        printf("Enter email: ");
        fgets(emails[i], sizeof(emails[i]), stdin);
        emails[i][strcspn(emails[i], "\n")] = '\0';

        printf("Enter phone: ");
        fgets(phones[i], sizeof(phones[i]), stdin);
        phones[i][strcspn(phones[i], "\n")] = '\0';

        printf("Enter town: ");
        fgets(towns[i], sizeof(towns[i]), stdin);
        towns[i][strcspn(towns[i], "\n")] = '\0';
    }

    printf("\n--- ALL SUPPLIERS ---\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("Name : %s\n", names[i]);
        printf("Email: %s\n", emails[i]);
        printf("Phone: %s\n", phones[i]);
        printf("Town : %s\n", towns[i]);
    }

    printf("\nEnter supplier name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(names[i], searchName) == 0)
        {
            found = 1;
            printf("\nSupplier found.\n");
            printf("Name : %s\n", names[i]);
            printf("Email: %s\n", emails[i]);
            printf("Phone: %s\n", phones[i]);
            printf("Town : %s\n", towns[i]);
            break;
        }
    }

    if (found == 0)
    {
        printf("\nSupplier not found.\n");
    }

    return 0;
}