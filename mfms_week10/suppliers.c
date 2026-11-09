#include <stdio.h>
#include <string.h>
#include "suppliers.h"
#include "utilities.h"

#define MAX_SUPPLIERS 50
#define TEXT_FILE "data/suppliers.txt"

static char supplierNames[MAX_SUPPLIERS][100];
static char emails[MAX_SUPPLIERS][100];
static char phones[MAX_SUPPLIERS][30];
static char towns[MAX_SUPPLIERS][50];
static int count = 0;

void addSupplier(void)
{
    if (count >= MAX_SUPPLIERS)
    {
        printf("The supplier list is full.\n");
        return;
    }

    readText("Enter supplier name: ", supplierNames[count], 100);
    readText("Enter email: ", emails[count], 100);
    readText("Enter phone: ", phones[count], 30);
    readText("Enter town: ", towns[count], 50);
    count++;

    printf("Supplier added.\n");
}

void listSuppliers(void)
{
    if (count == 0)
    {
        printf("No suppliers have been added yet.\n");
        return;
    }

    printf("\n--- SUPPLIERS ---\n");
    for (int i = 0; i < count; i++)
    {
        printf("Name : %s\n", supplierNames[i]);
        printf("Email: %s\n", emails[i]);
        printf("Phone: %s\n", phones[i]);
        printf("Town : %s\n\n", towns[i]);
    }
}

int saveSuppliersText(void)
{
    FILE *fp = fopen(TEXT_FILE, "w");

    if (fp == NULL)
    {
        perror(TEXT_FILE);
        return -1;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%s|%s|%s|%s\n", supplierNames[i], emails[i], phones[i], towns[i]);
    }

    fclose(fp);
    return count;
}

int loadSuppliersText(void)
{
    FILE *fp = fopen(TEXT_FILE, "r");
    char line[400];
    char name[100];
    char email[100];
    char phone[30];
    char town[50];
    int loaded = 0;

    if (fp == NULL)
    {
        return -1;
    }

    while (loaded < MAX_SUPPLIERS && fgets(line, sizeof(line), fp) != NULL)
    {
        if (sscanf(line, "%99[^|]|%99[^|]|%29[^|]|%49[^\n]", name, email, phone, town) == 4)
        {
            strcpy(supplierNames[loaded], name);
            strcpy(emails[loaded], email);
            strcpy(phones[loaded], phone);
            strcpy(towns[loaded], town);
            loaded++;
        }
    }

    fclose(fp);
    count = loaded;
    return loaded;
}