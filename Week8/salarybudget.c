#include <stdio.h>

float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);

int main()
{
    float basic;
    float housing;
    float transport;
    float salary;
    float revenue;
    float expenses;
    float result;

    printf("Basic salary: ");
    scanf("%f", &basic);

    printf("Housing allowance: ");
    scanf("%f", &housing);

    printf("Transport allowance: ");
    scanf("%f", &transport);

    salary = calculateSalary(basic, housing, transport);

    printf("\nGross salary: %.2f\n", salary);

    printf("\nEnter revenue: ");
    scanf("%f", &revenue);

    printf("Enter expenses: ");
    scanf("%f", &expenses);

    result = calculateBudget(revenue, expenses);

    printf("\nBudget balance: %.2f\n", result);

    if (result > 0)
    {
        printf("SURPLUS\n");
    }
    else if (result < 0)
    {
        printf("DEFICIT\n");
    }
    else
    {
        printf("BALANCED\n");
    }

    return 0;
}

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}