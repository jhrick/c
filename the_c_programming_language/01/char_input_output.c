#include <stdio.h>

// in unix-style-systems use Ctrl+d
// for provoke an end-of-file

int main() {
    int c, nl, blanks, tabs;

    int last_char;

    double nc;

    nc = 0;
    nl = 0;
    blanks = 0;
    tabs = 0;

    last_char = 0;
    while ((c = getchar()) != EOF) {
        if ((last_char != ' ' && last_char != c) || (last_char == ' ' && c != ' ')) {
            if (c == '\t') {
                putchar('\\');
                putchar('t');
                continue;
            } else if (c == '\b') {
                putchar('\\');
                putchar('b');
                continue;
            } else if (c == '\\') {
                putchar('\\');
                putchar('\\');
                continue;
            } else {
                putchar(c);
            }
        }

        last_char = c;

        ++nc;

        if (c == '\t') {
            ++tabs;
        } else if (c == ' ') {
            ++blanks;
        }
        
        if (c == '\n') {
            --nc;
            ++nl;
        }
    }

    printf("\nnumber characters: %.0f\n", nc);
    printf("number of lines: %d\n", nl);
    printf("number of blanks: %d\n", blanks);
    printf("number of tabs: %d\n", tabs);
     
    return 0;
}