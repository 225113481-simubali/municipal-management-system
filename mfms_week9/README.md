# MFMS - Week 9: Multi-File Programming

PAP521S Programming in Practice - Municipal Financial Management System (MFMS).

## Modules

- main.c - the menu and program flow. It calls the other modules.
- employees.c / employees.h - add, list and search employees, and the payroll total.
- budget.c / budget.h - add budget figures and calculate the balance.
- reports.c / reports.h - the employee report and the budget report.
- utilities.c / utilities.h - input helpers (readInt, readDouble, readText, pauseScreen).

Each .h file has an include guard and the function prototypes that other files may use.

## Build

gcc -std=c99 -Wall -Wextra -pedantic -c main.c
gcc -std=c99 -Wall -Wextra -pedantic -c employees.c
gcc -std=c99 -Wall -Wextra -pedantic -c budget.c
gcc -std=c99 -Wall -Wextra -pedantic -c utilities.c
gcc -std=c99 -Wall -Wextra -pedantic -c reports.c
gcc main.o employees.o budget.o utilities.o reports.o -o mfms

## Run

.\mfms.exe

## Test runs

See test_run1.txt, test_run2.txt and test_run3.txt.