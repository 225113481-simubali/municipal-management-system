
#include <stdio.h>

int main()
{
    float budget = 100000;

    float priceA = 95000;  int regA = 1;  int docsA = 1;
    float priceB = 88000;  int regB = 1;  int docsB = 1;
    float priceC = 82000;  int regC = 0;  int docsC = 1;
    float priceD = 91000;  int regD = 1;  int docsD = 0;

    int qualifiedA = 0, qualifiedB = 0, qualifiedC = 0, qualifiedD = 0;
    float lowest = 0;
    char preferred = ' ';

    if (regA == 1 && docsA == 1 && priceA <= budget) { qualifiedA = 1; }
    if (regB == 1 && docsB == 1 && priceB <= budget) { qualifiedB = 1; }
    if (regC == 1 && docsC == 1 && priceC <= budget) { qualifiedC = 1; }
    if (regD == 1 && docsD == 1 && priceD <= budget) { qualifiedD = 1; }

    if (qualifiedA == 1) { lowest = priceA; preferred = 'A'; }

    if (qualifiedB == 1 && (preferred == ' ' || priceB < lowest)) { lowest = priceB; preferred = 'B'; }
    if (qualifiedC == 1 && (preferred == ' ' || priceC < lowest)) { lowest = priceC; preferred = 'C'; }
    if (qualifiedD == 1 && (preferred == ' ' || priceD < lowest)) { lowest = priceD; preferred = 'D'; }

    printf("TENDER EVALUATION (Budget: %.2f)\n\n", budget);

    printf("Supplier A (%.2f): ", priceA);
    if (qualifiedA == 0) { printf("Disqualified\n"); }
    else if (preferred == 'A') { printf("Preferred Supplier\n"); }
    else { printf("Qualified\n"); }

    printf("Supplier B (%.2f): ", priceB);
    if (qualifiedB == 0) { printf("Disqualified\n"); }
    else if (preferred == 'B') { printf("Preferred Supplier\n"); }
    else { printf("Qualified\n"); }

    printf("Supplier C (%.2f): ", priceC);
    if (qualifiedC == 0) { printf("Disqualified\n"); }
    else if (preferred == 'C') { printf("Preferred Supplier\n"); }
    else { printf("Qualified\n"); }

    printf("Supplier D (%.2f): ", priceD);
    if (qualifiedD == 0) { printf("Disqualified\n"); }
    else if (preferred == 'D') { printf("Preferred Supplier\n"); }
    else { printf("Qualified\n"); }

    return 0;
}