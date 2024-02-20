#include <stdio.h>

#define MAXLINE 1000
#define LONGEST_CRITERION 80

int getln(char line[], int maxline);
void copy(char to[], char from[]);

int main(void) {
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getln(line, MAXLINE)) > 0) {
        if (len > max) {
            printf("longest-line size: %d, max permitted: %d\n", len, MAXLINE);
            max = len;
            copy(longest, line);
        }
        if (len >= LONGEST_CRITERION) {
            printf("\n%s\n", line);
        }
    }

    if (max > 0) {
        printf("%s\n", longest);
    }

    return 0;
}

int getln(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        while (c == ' ' || c == '\t') {
            c = getchar();
        }

        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        i++;
    }

    s[i] = '\0';

    return i;
}

void copy(char to[], char from[]) {
    int i;
    
    i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
    
    to[i] = '\0';
}