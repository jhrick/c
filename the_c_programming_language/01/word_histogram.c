#include <stdio.h>

int main(void) {
    int c;
    int bigger, i, j;
    int histogram[10];

    bigger = 0;

    for (i = 0; i < 10; i++) {
        histogram[i] = 0;
    }

    i = 0;

    while ((c = getchar()) != EOF) {
        if (c >= 'A' && c <= 'z') {
            ++histogram[i];
        }

        if (c == ' ' || c == '\t' || c == '\n') {
            if (i < 10) {
                ++i;
            } else {
                printf("this is limit\n");
                break;
            }
        }
    }

    printf("words length:\n\n");

    for (i = 0; i < 10; i++) {
        if (histogram[i] > bigger) bigger = histogram[i];
    }

    for (i = bigger; i > 0; --i) {
        for (j = 0; j < 10; ++j) {
            if (histogram[j] != i) {
                printf("  ");
            } else {
                printf(" #");
                --histogram[j];
            }
            if (j == 9) {
                printf("\n");
            }
        }
    }

    return 0;
}