#include <stdio.h>

int main() {
    int last_char, current_char;
    int words;

    last_char = 0;
    words = 0;

    while ((current_char = getchar()) != EOF) {
        if (last_char >= 'A' && current_char == ' ' || last_char >= 'A' && current_char == '\n') {
            ++words;
        }
        last_char = current_char;
    }
    
    printf("total words: %d\n", words);

    return 0;
}