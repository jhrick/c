#include <stdio.h>

// in unix-style-systems use Ctrl+d
// for provoke an end-of-file

int main() {
    long nc;

    nc = 0;
    while (getchar() != EOF)
        nc++;
    
    printf("number characters: %ld\n", nc);
    
    
    return 0;
}