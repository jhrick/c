#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

/* printf Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300*/

int main() {
    float fahr, celsius;

    printf("from Fahrenheit to Celsius:\n\n");

    fahr = LOWER;

    while (fahr <= UPPER) {
        celsius = 5.0 * (fahr - 32.0) / 9.0;
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += STEP;
    }

    printf("\nfrom Celsius to Fahrenheit:\n\n");

    celsius = LOWER;

    while (celsius <= UPPER) {
        fahr = celsius / 5.0 * 9.0 + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius += STEP;
    }
    
    printf("\nfrom Fahrenheit to Celsius (reverse table):\n\n");
    
    for (fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
        printf("%3.0f %6.1f\n", fahr, 5.0 * (fahr - 32) / 9);
    }

    printf("\nfrom Celsius to Fahrenheit (reverse table):\n\n");
    
    for (celsius = UPPER; celsius >= LOWER; celsius -= STEP) {
        printf("%3.0f %6.1f\n", celsius, celsius / 5 * 9 + 32);
    }
}