#include <stdio.h>

int main() {

    int departments;
    double payroll;
    double procurement;
    double assets;

    printf("MUNICIPAL FINANCIAL SUMMARY\n");

    printf("Enter number of departments: ");
    scanf("%d", &departments);

    printf("Enter payroll: ");
    scanf("%lf", &payroll);

    printf("Enter procurement: ");
    scanf("%lf", &procurement);

    printf("Enter assets: ");
    scanf("%lf", &assets);

    printf("\nDepartments: %d\n", departments);
    printf("Payroll: %.2f\n", payroll);
    printf("Procurement: %.2f\n", procurement);
    printf("Assets: %.2f\n", assets);

    return 0;
}