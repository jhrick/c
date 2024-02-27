#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1028

char * get_word();

int main(void) {
  char * word = get_word();

  printf("%s\n", word);

  return 0;
}

char * get_word() {
  int i, c;
  int bufsize = BUFSIZE;
  char *word;
  FILE *words_file;
  words_file = fopen("words.txt", "r");

  word = malloc(sizeof(char) * bufsize);

  if (word == NULL) {
    fprintf(stderr, "allocation error");
    exit(EXIT_FAILURE);
  }

  i = 0;

  if (words_file) {
    while ((c = getc(words_file)) != EOF) {
      if (c == '\n') {
        break;
      }

      word[i] = c;
      i++;

      if (i >= bufsize) {
        bufsize += BUFSIZE;
        word = realloc(word, bufsize);

        if (word == NULL) {
          fprintf(stderr, "allocation error");
          exit(EXIT_FAILURE);
        }
      }
    }
  }

  return word;
}
