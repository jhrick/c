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
    int i;

    printf("fahr: %d\n", to_fahrenheit(100));
    printf("celsius: %d\n", to_celsius(212));

    return 0;
}