#include <stdio.h>
#include "assets.h"
#include "records.h"
#include "utilities.h"

#define FILE_NAME "data/assets.dat"

static Asset assets[MAX_RECORDS];
static int assetCount = 0;

void addAsset(void)
{
    if (assetCount >= MAX_RECORDS)
    {
        printf("The asset list is full.\n");
        return;
    }

    assets[assetCount].id = readInt("Enter asset ID: ");
    readText("Enter description: ", assets[assetCount].description, 40);
    assets[assetCount].value = readDouble("Enter value: ");
    assets[assetCount].acquired.day = readInt("Enter day acquired: ");
    assets[assetCount].acquired.month = readInt("Enter month acquired: ");
    assets[assetCount].acquired.year = readInt("Enter year acquired: ");
    assetCount++;

    printf("Asset added.\n");
}

void displayAssets(void)
{
    if (assetCount == 0)
    {
        printf("No assets have been added yet.\n");
        return;
    }

    printf("\n%-6s %-25s %14s %-12s\n", "ID", "Description", "Value", "Acquired");
    for (int i = 0; i < assetCount; i++)
    {
        printf("%-6d %-25s %14.2f %02d/%02d/%d\n",
               assets[i].id, assets[i].description, assets[i].value,
               assets[i].acquired.day, assets[i].acquired.month,
               assets[i].acquired.year);
    }
}

int saveAssetsBinary(void)
{
    FILE *fp = fopen(FILE_NAME, "wb");
    size_t written;

    if (fp == NULL)
    {
        perror(FILE_NAME);
        return -1;
    }

    written = fwrite(assets, sizeof assets[0], assetCount, fp);
    fclose(fp);

    if ((int)written != assetCount)
    {
        return -1;
    }

    return assetCount;
}

int loadAssetsBinary(void)
{
    FILE *fp = fopen(FILE_NAME, "rb");
    size_t loaded;

    if (fp == NULL)
    {
        return -1;
    }

    loaded = fread(assets, sizeof assets[0], MAX_RECORDS, fp);
    fclose(fp);

    assetCount = (int)loaded;
    return assetCount;
}