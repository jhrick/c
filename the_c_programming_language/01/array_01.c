#include <stdio.h>

int main(void) {
    int c, i, nwhite, nother;
    int ndigits[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; i++) {
        ndigits[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            ++ndigits[c-'0'];
        } else if (c == ' ' || c == '\t' || c == '\n') {
            ++nwhite;
        } else {
            ++nother;
        }
    }

    printf("digits =");
    for (i = 0; i < 10; i++) {
        printf(" %d", ndigits[i]);
    }

    printf(" white spaces = %d, others: %d\n");

    return 0;
}