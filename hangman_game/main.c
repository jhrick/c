#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFSIZE 1028
#define MAX_ATTEMPS 3
#define NEWLINE_AND_NULL_CHAR 2

int word_size;
char right_words[BUFSIZE];
int failed_attemps;
int victory;

char * get_word();

void check_victory(char *word) {
  int i, check;

  for (i = 0; i <= (sizeof(word) - (NEWLINE_AND_NULL_CHAR + 1)); i++) {
    if (!(right_words[i] == word[i])) {
      break;
    }

    if (i == (sizeof(word) - (NEWLINE_AND_NULL_CHAR + 1))) {
      printf("you win!\n");
      victory = 1;
    }
  }
}

void check_guessed(char *word) {
  int i;

  i = 0;

  while (i < word_size) {
    if (right_words[i] != '\0') {
      printf(" %c ", right_words[i]);
    } else {
      printf(" _ ");
    }

    if ((i + 1) >= word_size) {
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
      check_victory(word);
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
    } else if (victory) {
      printf("you win\n");
      break;
    }
  }
}

int main(void) {
  game_loop();

  return 0;
}

int count_lines(FILE *file) {
  int c;
  int count;

  count = 0;

  while ((c = getc(file)) != EOF) {
    if (c == '\n') count++;
  }
  
  rewind(file); // go back to the beginning of the file
  return count;
}

char * get_word(void) {
  int c, current_line, nline, position;
  srand(time(NULL));

  int lines;
  int bufsize = BUFSIZE;
  char *word;
  FILE *words_file;
  words_file = fopen("words.txt", "r");

  word = malloc(sizeof(char) * bufsize);

  word_size = 0;
  lines = count_lines(words_file);
  int random_line = rand() % lines + 1;

  if (word == NULL) {
    fprintf(stderr, "allocation error");
    exit(EXIT_FAILURE);
  }

  printf("random_line = %d\n", random_line);

  current_line = 1;
  position = 0;

  if (words_file) {
    while ((c = getc(words_file)) != EOF) {
      if (c == '\n') {
        current_line++;
        c = getc(words_file);
      }

      if (current_line == random_line) {
        word[position] = c;
        position++;
        word_size++;
      }

      if (position >= bufsize) {
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
