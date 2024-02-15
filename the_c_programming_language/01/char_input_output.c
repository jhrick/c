#include <stdio.h>

// in unix-style-systems use Ctrl+d
// for provoke an end-of-file

int main() {
    double nc;

    for (nc = 0; getchar() != EOF; ++nc);
    
    printf("number characters: %.0f\n", nc);
     
    return 0;
}