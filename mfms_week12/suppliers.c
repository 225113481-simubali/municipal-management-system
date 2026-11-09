#include <stdio.h>
#include "suppliers.h"
#include "records.h"
#include "utilities.h"

#define FILE_NAME "data/suppliers.dat"

static Supplier suppliers[MAX_RECORDS];
static int supplierCount = 0;

void addSupplier(void)
{
    if (supplierCount >= MAX_RECORDS)
    {
        printf("The supplier list is full.\n");
        return;
    }

    suppliers[supplierCount].id = readInt("Enter supplier ID: ");
    readText("Enter name: ", suppliers[supplierCount].name, 40);
    readText("Enter email: ", suppliers[supplierCount].email, 40);
    readText("Enter phone: ", suppliers[supplierCount].phone, 15);
    readText("Enter town: ", suppliers[supplierCount].town, 20);
    supplierCount++;

    printf("Supplier added.\n");
}

void displaySuppliers(void)
{
    if (supplierCount == 0)
    {
        printf("No suppliers have been added yet.\n");
        return;
    }

    printf("\n%-6s %-22s %-24s %-12s %-12s\n", "ID", "Name", "Email", "Phone", "Town");
    for (int i = 0; i < supplierCount; i++)
    {
        printf("%-6d %-22s %-24s %-12s %-12s\n",
               suppliers[i].id, suppliers[i].name, suppliers[i].email,
               suppliers[i].phone, suppliers[i].town);
    }
}

int saveSuppliersBinary(void)
{
    FILE *fp = fopen(FILE_NAME, "wb");
    size_t written;

    if (fp == NULL)
    {
        perror(FILE_NAME);
        return -1;
    }

    written = fwrite(suppliers, sizeof suppliers[0], supplierCount, fp);
    fclose(fp);

    if ((int)written != supplierCount)
    {
        return -1;
    }

    return supplierCount;
}

int loadSuppliersBinary(void)
{
    FILE *fp = fopen(FILE_NAME, "rb");
    size_t loaded;

    if (fp == NULL)
    {
        return -1;
    }

    loaded = fread(suppliers, sizeof suppliers[0], MAX_RECORDS, fp);
    fclose(fp);

    supplierCount = (int)loaded;
    return supplierCount;
}