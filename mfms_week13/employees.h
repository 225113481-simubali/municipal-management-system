#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include "records.h"

void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
double calculatePayrollTotal(void);
int getEmployeeCount(void);
void updateSalary(Employee *e, double newSalary);
Employee *findEmployee(Employee list[], int n, int id);
void updateEmployeeSalary(void);
int saveEmployeesBinary(void);
int loadEmployeesBinary(void);

#endif