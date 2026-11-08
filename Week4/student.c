#include <stdio.h>

int main()
{
    char studentName[50];
    int test1;
    int test2;
    int assignment;
    int total;

    printf("Enter student name: ");
    scanf("%49s", studentName);

    printf("Enter Test 1 mark: ");
    scanf("%d", &test1);

    printf("Enter Test 2 mark: ");
    scanf("%d", &test2);

    printf("Enter Assignment mark: ");
    scanf("%d", &assignment);

    total = test1 + test2 + assignment;

    printf("\nStudent: %s\n", studentName);
    printf("Total: %d\n", total);

    if (total >= 75)
    {
        printf("Result: Distinction\n");
    }
    else if (total >= 60)
    {
        printf("Result: Credit\n");
    }
    else if (total >= 50)
    {
        printf("Result: Pass\n");
    }
    else
    {
        printf("Result: Fail\n");
    }

    return 0;
}