#include <stdio.h>

int main(void) {
    int c, i, nword, state;
    int histogram[10];

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
        printf("%2d: ", i + 1);
        for (int lenght = 0; lenght < histogram[i]; lenght++) {
            printf("# ");
        }
        printf("\n");
    }

    return 0;
}