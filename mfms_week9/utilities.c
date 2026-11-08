#include <stdio.h>
#include <string.h>
#include "utilities.h"

int readInt(const char *prompt)
{
    char line[100];
    int value;

    while (1)
    {
        printf("%s", prompt);

        if (fgets(line, sizeof(line), stdin) == NULL)
        {
            return 0;
        }

        if (sscanf(line, "%d", &value) == 1)
        {
            return value;
        }

        printf("Invalid input. Please enter a whole number.\n");
    }
}

double readDouble(const char *prompt)
{
    char line[100];
    double value;

    while (1)
    {
        printf("%s", prompt);

        if (fgets(line, sizeof(line), stdin) == NULL)
        {
            return 0;
        }

        if (sscanf(line, "%lf", &value) == 1)
        {
            return value;
        }

        printf("Invalid input. Please enter a number.\n");
    }
}

void readText(const char *prompt, char text[], int size)
{
    printf("%s", prompt);

    if (fgets(text, size, stdin) == NULL)
    {
        text[0] = '\0';
        return;
    }

    text[strcspn(text, "\n")] = '\0';
}

void pauseScreen(void)
{
    char line[100];

    printf("\nPress Enter to continue...");
    fgets(line, sizeof(line), stdin);
}