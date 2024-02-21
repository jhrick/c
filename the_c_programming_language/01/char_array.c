#include <stdio.h>

#define MAXLINE 1000
#define LONGEST_CRITERION 80
#define REMOVE_NULL_CHAR 1

int getln(char line[], int maxline);
void copy(char to[], char from[]);

void reverse(char s[], char to[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        to[i] = s[(size - i) - REMOVE_NULL_CHAR];
    }
}

int main(void) {
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];
    char reverse_line[MAXLINE];

    max = 0;
    while ((len = getln(line, MAXLINE)) > 0) {
        reverse(line, reverse_line, len);

        if (len > max) {
            printf("longest-line size: %d, max permitted: %d\n", len, MAXLINE);
            max = len;
            copy(longest, line);
        }
        if (len >= LONGEST_CRITERION) {
            printf("\n%s\n", line);
        }

        printf("reverse: %s\n", reverse_line);
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