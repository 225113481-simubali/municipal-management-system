# MFMS - Week 10: File Handling

All data is saved in the data folder. Run the program from this folder.

Text files (employees.txt, suppliers.txt, assets.txt, budgets.txt):
- Written with fprintf, one record per line, fields separated by |.
- Read back with fgets and sscanf.
- Human-readable and easy to check or edit by hand.
- A field that contains the | character would break the format.

Binary file (employees.dat):
- Written with fwrite and read with fread, one fixed-size record at a time.
- Each record is 64 bytes, so 2 employees give a 128 byte file.
- Not readable in a text editor.
- It depends on the computer's data sizes, so it is not a portable format.

Save Data uses "w", which replaces the old file with the current records.
If a data file is missing, Load Data reports it and the program carries on.

Build:

gcc -std=c99 -Wall -Wextra -pedantic -c main.c
gcc -std=c99 -Wall -Wextra -pedantic -c employees.c
gcc -std=c99 -Wall -Wextra -pedantic -c suppliers.c
gcc -std=c99 -Wall -Wextra -pedantic -c assets.c
gcc -std=c99 -Wall -Wextra -pedantic -c budget.c
gcc -std=c99 -Wall -Wextra -pedantic -c storage.c
gcc -std=c99 -Wall -Wextra -pedantic -c utilities.c
gcc -std=c99 -Wall -Wextra -pedantic -c reports.c
gcc main.o employees.o suppliers.o assets.o budget.o storage.o utilities.o reports.o -o mfms