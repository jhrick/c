#include <stdio.h>

#define IN  1   /* inside a word */
#define OUT 0   /* outside a word */

int main() {
    int current_ch, lines, words, chars, state;

    state = OUT;
    lines = words = chars = 0;

    while ((current_ch = getchar()) != EOF) {
        ++chars;

        if (current_ch == '\n') {
            ++lines;
        }

        if (current_ch == ' ' || current_ch == '\n' || current_ch == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++words;
        }
    }
    
    printf("lines: %d, words: %d, chars: %d\n", lines, words, chars);

    return 0;
}