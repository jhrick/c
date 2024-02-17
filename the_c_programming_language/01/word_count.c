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

        if (current_ch == ' ' && state == IN || current_ch == '\n' && state == IN) {
            printf("\n");
        } 

        if (current_ch == ' ' || current_ch == '\n' || current_ch == '\t') {
            state = OUT;
        } else if (current_ch >= 'A' && current_ch <= 'z') {
            if (state == OUT) {
              state = IN;
              ++words;
            }

            putchar(current_ch);
        }
    }
    
    printf("lines: %d, words: %d, chars: %d\n", lines, words, chars);

    return 0;
}