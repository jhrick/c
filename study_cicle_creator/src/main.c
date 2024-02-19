#include <stdio.h>

#define QTD_SUBJECTS 10

char * subjects[] = {
    "math",
    "portuguese",
    "geography",
    "history",
    "biology",
    "philosophy",
    "sociology",
    "chemical",
    "physics",
    "english"
};

void create_study_cicle(void) {
    int i, c;
    int difficult_each_suject[QTD_SUBJECTS];

    printf("1: excellent; 2: good; 3: ok; 4: bad; 5: too bad\n");

    i = 0;

    while (c != EOF) {
        if (c != '\n') {
            printf("%s: ", subjects[i]);
        }

        c = getchar();

        if (c >= '1' && c <= '5') {
            difficult_each_suject[i] = c-'0';
            i++;
        }

        if (i == (QTD_SUBJECTS)) {
            c = EOF;
        }
    }
    return;
}

int main(void) {
    create_study_cicle();

    return 0;
}