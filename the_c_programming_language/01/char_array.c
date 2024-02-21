#include <stdio.h>

#define MAXLINE 1000
#define LONGEST_CRITERION 80
#define REMOVE_NULL_CHAR 1

int max;
char line[MAXLINE];
char longest[MAXLINE];
char reverse_line[MAXLINE];

int getln();
void copy();

void reverse(int size) {
    int i;
    extern char line[];
    extern char reverse_line[];

    for (i = 0; i < size; i++) {
        reverse_line[i] = line[(size - i) - REMOVE_NULL_CHAR];
    }
}

int main(void) {
    int len;
    extern int max;
    extern char longest[MAXLINE];

    max = 0;
    while ((len = getln()) > 0) {
        reverse(len);

        if (len > max) {
            printf("longest-line size: %d, max permitted: %d\n", len, MAXLINE);
            max = len;
            copy();
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

int getln() {
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        while (c == ' ' || c == '\t') {
            c = getchar();
        }

        line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;
        i++;
    }

    line[i] = '\0';

    return i;
}

void copy() {
    int i;
    extern char line[];
    extern char longest[];
    
    i = 0;
    while ((longest[i] = line[i]) != '\0') {
        i++;
    }
    
    longest[i] = '\0';
}