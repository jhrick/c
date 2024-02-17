#include <stdio.h>

int to_fahrenheit(int celsius);
int to_celsius(int fahr);

int to_fahrenheit(int celsius) {
    int fahr;

    fahr = (celsius / 5) * 9 + 32;
    
    return fahr;
}

int to_celsius(int fahr) {
    int celsius;

    celsius = 5 * (fahr - 32) / 9;

    return celsius;
}

int main (void) {
    int c;
    int value;

    printf("what temperature you want get?\nc - celsius\tf - fahrenheit\n");

    c = getchar();

    if (c == 'c') {
        printf("please, insert the value from fahrenheit at you want convert to celsius: ");
        scanf("%d", &value);

        printf("fahrenheit = %d, celsius = %d\n", value, to_celsius(value));
    } else if (c == 'f') {
        printf("please, insert the value from celsius at you want convert to fahrenheit: ");
        scanf("%d", &value);

        printf("celsius = %d, fanrenheit = %d\n", value, to_fahrenheit(value));
    } else {
        printf("sorry, but I don't have this option");
    }

    return 0;
}