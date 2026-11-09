#include <stdio.h>
#include "projects.h"
#include "records.h"
#include "utilities.h"

#define FILE_NAME "data/projects.dat"

static Project projects[MAX_RECORDS];
static int projectCount = 0;

void addProject(void)
{
    if (projectCount >= MAX_RECORDS)
    {
        printf("The project list is full.\n");
        return;
    }

    projects[projectCount].id = readInt("Enter project ID: ");
    readText("Enter title: ", projects[projectCount].title, 40);
    projects[projectCount].budget = readDouble("Enter budget: ");
    projects[projectCount].startDate.day = readInt("Enter start day: ");
    projects[projectCount].startDate.month = readInt("Enter start month: ");
    projects[projectCount].startDate.year = readInt("Enter start year: ");
    projects[projectCount].endDate.day = readInt("Enter end day: ");
    projects[projectCount].endDate.month = readInt("Enter end month: ");
    projects[projectCount].endDate.year = readInt("Enter end year: ");
    projectCount++;

    printf("Project added.\n");
}

void displayProjects(void)
{
    if (projectCount == 0)
    {
        printf("No projects have been added yet.\n");
        return;
    }

    printf("\n%-6s %-25s %14s %-12s %-12s\n", "ID", "Title", "Budget", "Start", "End");
    for (int i = 0; i < projectCount; i++)
    {
        printf("%-6d %-25s %14.2f %02d/%02d/%d   %02d/%02d/%d\n",
               projects[i].id, projects[i].title, projects[i].budget,
               projects[i].startDate.day, projects[i].startDate.month,
               projects[i].startDate.year,
               projects[i].endDate.day, projects[i].endDate.month,
               projects[i].endDate.year);
    }
}

int saveProjectsBinary(void)
{
    FILE *fp = fopen(FILE_NAME, "wb");
    size_t written;

    if (fp == NULL)
    {
        perror(FILE_NAME);
        return -1;
    }

    written = fwrite(projects, sizeof projects[0], projectCount, fp);
    fclose(fp);

    if ((int)written != projectCount)
    {
        return -1;
    }

    return projectCount;
}

int loadProjectsBinary(void)
{
    FILE *fp = fopen(FILE_NAME, "rb");
    size_t loaded;

    if (fp == NULL)
    {
        return -1;
    }

    loaded = fread(projects, sizeof projects[0], MAX_RECORDS, fp);
    fclose(fp);

    projectCount = (int)loaded;
    return projectCount;
}