#include <stdio.h>

// in unix-style-systems use Ctrl+d
// for provoke an end-of-file

int main() {
    int c, nl;
    double nc;

    nl = 0;
    for (nc = 0;(c = getchar()) != EOF; ++nc) {
        if (c == '\n') ++nl;
    }

    printf("number characters: %.0f\n", nc);
    printf("number of lines: %d\n", nl);
     
    return 0;
}