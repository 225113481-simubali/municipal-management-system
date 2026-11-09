#include <stdio.h>
#include <string.h>
#include "assets.h"
#include "utilities.h"

#define MAX_ASSETS 100
#define TEXT_FILE "data/assets.txt"

static char assetNames[MAX_ASSETS][50];
static double assetValues[MAX_ASSETS];
static int count = 0;

void addAsset(void)
{
    if (count >= MAX_ASSETS)
    {
        printf("The asset list is full.\n");
        return;
    }

    readText("Enter asset name: ", assetNames[count], 50);
    assetValues[count] = readDouble("Enter asset value: ");
    count++;

    printf("Asset added.\n");
}

void listAssets(void)
{
    if (count == 0)
    {
        printf("No assets have been added yet.\n");
        return;
    }

    printf("\n--- ASSETS ---\n");
    for (int i = 0; i < count; i++)
    {
        printf("Asset: %s | Value: %.2f\n", assetNames[i], assetValues[i]);
    }
}

int saveAssetsText(void)
{
    FILE *fp = fopen(TEXT_FILE, "w");

    if (fp == NULL)
    {
        perror(TEXT_FILE);
        return -1;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%s|%.2f\n", assetNames[i], assetValues[i]);
    }

    fclose(fp);
    return count;
}

int loadAssetsText(void)
{
    FILE *fp = fopen(TEXT_FILE, "r");
    char line[200];
    char name[50];
    double value;
    int loaded = 0;

    if (fp == NULL)
    {
        return -1;
    }

    while (loaded < MAX_ASSETS && fgets(line, sizeof(line), fp) != NULL)
    {
        if (sscanf(line, "%49[^|]|%lf", name, &value) == 2)
        {
            strcpy(assetNames[loaded], name);
            assetValues[loaded] = value;
            loaded++;
        }
    }

    fclose(fp);
    count = loaded;
    return loaded;
}