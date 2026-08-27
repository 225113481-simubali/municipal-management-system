#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main(void)
{
    char municipalityName[MAX_LEN];
    char mayorName[MAX_LEN];
    long population = 0;

    printf("==================================================");
    printf("  MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("==================================================");

    printf("Welcome to Windhoek Municipality\n\n");

    printf("Please enter the following details:\n");

    printf("Municipality Name: ");
    fgets(municipalityName, MAX_LEN, stdin);
    municipalityName[strcspn(municipalityName, "\n")] = '\0';

    printf ("Mayor's Name: ");
    fgets(mayorName, MAX_LEN, stdin);
    mayorName[strcspn(mayorName, "\n")] = '\0';

    printf("Population: ");
    scanf("%ld", &population);
    
    printf("\n===================================================\n");
    printf("      MUNICIPAL REPORT\n");
    printf("====================================================\n");
    printf("%-20s: %s\n","Municipality Name",municipalityName);
    printf("%-20s: %s\n","Mayor's Name",mayorName);
    printf("%-20s: %ld\n","Population",population);
    printf("======================================================\n");

    return 0;
}
