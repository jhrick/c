#include <stdio.h>

#define TAB_TO_SPACE 8
#define MAXLINE 1000

char line[MAXLINE];
int ncolumns;
int columns;

void to_space(int current_position) {
  int i;

  for (i = 0; i < 8; i++) {
    line[current_position + i] = ' ';
  }
}

int getln() {
  int i, c;
  extern char line[];

  ncolumns = 0;
  for (i = 0; i < MAXLINE && (c = getchar()) != EOF && c != '\n'; i++) {
    if (c == '\t') {
      to_space(i);
      i += (TAB_TO_SPACE - 1);
      ncolumns++;
    } else {
      line[i] = c;
    }

    if (ncolumns == columns) {
      line[i] = '\n';
      ncolumns = 0;
    }
  }

  return i;
}

int main(void) {
  extern char line[];

  printf("how many columns you want? \n");
  columns = getchar() - '0';
  getchar(); // get '\n' char

  getln();

  printf("\n%s\n", line);

  return 0;
}
