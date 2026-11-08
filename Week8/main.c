#include <stdio.h>

void displayWelcome();
float calculateVAT(float amount);

int main()
{
    float amount;
    float vat;

    displayWelcome();

    printf("Enter amount: ");
    scanf("%f", &amount);

    vat = calculateVAT(amount);

    printf("\nVAT: %.2f\n", vat);

    return 0;
}

void displayWelcome()
{
    printf("Welcome to the Municipal Financial Management System\n");
}

float calculateVAT(float amount)
{
    return amount * 0.15;
}