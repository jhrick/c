#include <stdio.h>

#define ALPHABET_LENGTH 26 /* just lowercase letters */
#define ALPHABET_POSITION 49

// this program just
// count lowercase letters

int main(void) {
    int c;
    int bigger, i, j;
    char ndiferents_chars[ALPHABET_LENGTH];

    bigger = 0;

    for (i = 0; i < ALPHABET_LENGTH; i++) {
        ndiferents_chars[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z') {
            ++ndiferents_chars[(c-'0') - ALPHABET_POSITION];
        }
    }

    for (i = 0; i < ALPHABET_LENGTH; i++) {
        if (bigger < ndiferents_chars[i]) {
            bigger = ndiferents_chars[i];
        }
    }

    printf("\n");

    for (i = bigger; i > 0; i--) {
        for (j = 0; j < ALPHABET_LENGTH; j++) {
            if (ndiferents_chars[j] != i) {
                printf("  ");
            } else {
                printf(" *");
                --ndiferents_chars[j];
            }

            if (j == (ALPHABET_LENGTH - 1)) {
                printf("\n");
            }
        }
    }

    return 0;
}