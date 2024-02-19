#include <stdio.h>
#include <stdlib.h>

#define QTD_SUBJECTS 10
#define MIN_STUDY_HOURS 2

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

double round_hours(double hours) {
    double rounded_hours;
    int int_part;
    double dec_part;

    if (hours < MIN_STUDY_HOURS) {
        rounded_hours = MIN_STUDY_HOURS;
    } else {
        int_part = (int)hours;
        dec_part = hours - int_part;

        if (dec_part <= 5) {
            rounded_hours = int_part;
        } else {
            rounded_hours = (int_part + 1);
        }
    }

    return rounded_hours;
}

int * get_subject_difficulty(void) {
    int i, c;
    int *difficult_in_each_suject = malloc(QTD_SUBJECTS * sizeof(int));

    if (!difficult_in_each_suject) {
        return NULL;
    }

    printf("1: excellent; 2: good; 3: ok; 4: bad; 5: too bad\n");

    i = 0;

    while (c != EOF) {
        if (c != '\n') {
            printf("%s: ", subjects[i]);
        }

        c = getchar();

        if (c >= '1' && c <= '5') {
            difficult_in_each_suject[i] = c-'0';
            i++;
        }

        if (i == (QTD_SUBJECTS)) {
            c = EOF;
        }
    }
    return difficult_in_each_suject;
}

double * calculate_study_hours_per_subject(int * difficult_in_each_suject) {
    int i;
    double hours_per_day, days_per_week;
    int total_difficulty_hours;
    double study_hours_per_difficulty;
    double * subject_study_hours = malloc(QTD_SUBJECTS * sizeof(int));

    if (!subject_study_hours) {
        return NULL;
    }

    total_difficulty_hours = 0;

    for (i = 0; i < QTD_SUBJECTS; i++) {
        total_difficulty_hours += difficult_in_each_suject[i];
    }
        printf("%d\n", total_difficulty_hours);

    printf("how many hours you want study per day? ");

    getchar(); // consume newline
    hours_per_day = getchar() - '0';

    printf("how many days you want study per week? ");

    getchar(); // consume newline
    days_per_week = getchar() - '0';

    study_hours_per_difficulty = (hours_per_day * days_per_week) / total_difficulty_hours;

    printf("%.2f, %d\n", (hours_per_day * days_per_week), total_difficulty_hours);

    for (i = 0; i < QTD_SUBJECTS; i++) {
        subject_study_hours[i] = round_hours(study_hours_per_difficulty * difficult_in_each_suject[i]);
    }

    return subject_study_hours;
}

void create_study_cicle() {
    int i;
    int * difficult_in_each_suject;
    double *subject_study_hours;

    difficult_in_each_suject = get_subject_difficulty();

    subject_study_hours = calculate_study_hours_per_subject(difficult_in_each_suject);

    for (i = 0; i < QTD_SUBJECTS; i++) {
        printf("%s: %2.2fhrs\n", subjects[i], subject_study_hours[i]);
    }

    free(difficult_in_each_suject);
    free(subject_study_hours);

    return;
}

int main(void) {
    create_study_cicle();

    return 0;
}