#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage(char *calculator) {

    printf("Uzycie: %s liczba 1 liczba 2 operacja\n", calculator);
    printf("Dostepne operacje: add, sub, mul, div\n");
}

int main(int argc, char *argv[]) {

    int number1 = 0;
    int number2 = 0;
    int result = 0;

    if (argc == 4) {
        number1 = atoi(argv[1]);
        number2 = atoi(argv[2]);

        if(strcmp("add", argv[3]) == 0 ) {
            result = number1 + number2;
            printf("%d + %d = %d\n", number1, number2, result);
        } else if (strcmp("sub", argv[3]) == 0 ) {
            result = number1 - number2;
            printf("%d - %d = %d\n", number1, number2, result);
        } else if (strcmp("mul", argv[3]) == 0 ) {
            result = number1 * number2;
            printf("%d * %d = %d\n", number1, number2, result);
        } else if (strcmp("div", argv[3]) == 0 ) {
            if (number2 != 0) {
                result = number1 / number2;
                printf("%d / %d = %d\n", number1, number2, result);
            } else {
                printf("Blad: dzielnie przez 0!\n");
            }
        } else {
            usage(argv[0]);
        }
    } else {
        usage(argv[0]);
    }
    return 0;
}
