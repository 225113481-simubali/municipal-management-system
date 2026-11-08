#include <stdio.h>

int main() {

    printf("for loop:\n");
    for (int i = 1; i <= 5; i++) {
        printf("%d\n", i);
    }

    printf("\nwhile loop:\n");
    int number = 1;
    while (number <= 5) {
        printf("%d\n", number);
        number++;
    }

    printf("\ndo...while loop:\n");
    int count = 1;
    do {
        printf("%d\n", count);
        count++;
    } while (count <= 5);

    printf("\nbreak (stops at 6):\n");
    for (int i = 1; i <= 10; i++) {
        if (i == 6) {
            break;
        }
        printf("%d\n", i);
    }

    printf("\ncontinue (skips 5):\n");
    for (int i = 1; i <= 10; i++) {
        if (i == 5) {
            continue;
        }
        printf("%d\n", i);
    }

    return 0;
}