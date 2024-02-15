#include <stdio.h>

/* printf Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300*/

int main() {
    float fahr, celsius;

    int lower = 0;
    int upper = 300;
    int step = 20;

    printf("from Fahrenheit to Celsius:\n\n");

    fahr = lower;

    while (fahr <= upper) {
        celsius = 5.0 * (fahr - 32.0) / 9.0;
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += step;
    }

    printf("\nfrom Celsius to Fahrenheit:\n\n");

    celsius = lower;

    while (celsius <= upper) {
        fahr = celsius / 5.0 * 9.0 + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius += step;
    }
    
}