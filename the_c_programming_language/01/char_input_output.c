#include <stdio.h>

// in unix-style-systems use Ctrl+d
// for provoke an end-of-file

int main() {
    int c, nl, blanks, tabs;
    double nc;

    nc = 0;
    nl = 0;
    blanks = 0;
    tabs = 0;
    while ((c = getchar()) != EOF) {
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

    printf("number characters: %.0f\n", nc);
    printf("number of lines: %d\n", nl);
    printf("number of blanks: %d\n", blanks);
    printf("number of tabs: %d\n", tabs);
     
    return 0;
}