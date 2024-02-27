#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1028
#define MAX_ATTEMPS 3
#define NEWLINE_AND_NULL_CHAR 2

char right_words[BUFSIZE];
int failed_attemps;

char * get_word();

void check_guessed(char *word) {
  int i;

  i = 0;

  while (i < (sizeof(word) - NEWLINE_AND_NULL_CHAR)) {
    if (right_words[i] != '\0') {
      printf(" %c ", right_words[i]);
    } else {
      printf(" _ ");
    }

    if ((i + 1) >= (sizeof(word) - NEWLINE_AND_NULL_CHAR)) {
      printf("\n");
    }
    i++;
  }
}

void check_char(int *c, char *word) {
  int i;
  int have_char;

  i = 0;
  have_char = 0;

  do {
    if (*c == word[i]) {
      right_words[i] = *c;
      have_char = 1;
    }
    i++;
  } while (word[i] != '\0');

  if (!have_char) failed_attemps++;
}

void game_loop(void) {
  int c, *char_pointer;
  char *word = get_word();
  
  failed_attemps = 0;
  char_pointer = &c;

  printf("%s\n", word);

  while ((c = getchar())) {
    getchar(); // skips '\n'
    check_char(char_pointer, word);
    check_guessed(word);

    printf("failed_attemps = %d\n", failed_attemps);

    if (failed_attemps == MAX_ATTEMPS) {
      printf("you lose.\n");
      break;
    }
  }
}

int main(void) {
  game_loop();

  return 0;
}

char * get_word(void) {
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
