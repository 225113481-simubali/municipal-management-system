#include <stdio.h>
#include <string.h>

int main()
{
    char original[100];
    char backup[100];
    char town[50];
    char sentence[200];

    printf("Enter supplier name: ");
    fgets(original, sizeof(original), stdin);
    original[strcspn(original, "\n")] = '\0';

    printf("Enter town: ");
    fgets(town, sizeof(town), stdin);
    town[strcspn(town, "\n")] = '\0';

    strcpy(backup, original);

    printf("\nOriginal: %s\n", original);
    printf("Backup  : %s\n", backup);

    strcpy(sentence, original);
    strcat(sentence, " operates in ");
    strcat(sentence, town);
    strcat(sentence, ".");

    printf("\n%s\n", sentence);

    return 0;
}