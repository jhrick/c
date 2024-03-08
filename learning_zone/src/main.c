#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1000
#define STR_DELIM " \t\n\r\a"

int args_lenght = 0;

char *read_line(void) {
  int c, i;
  char *line = malloc(sizeof(char) * BUFSIZE);

  i = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      break;
    }

    line[i] = c;
    ++i;
  }

  line[i] = '\0';

  return line;
}

char **split_line(char *line) {
  int position;
  int bufsize = BUFSIZE;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (tokens == NULL) {
    perror("allocation error");
    exit(EXIT_FAILURE);
  }

  position = 0;

  token = strtok(line, STR_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    ++position;

    if (position > bufsize) {
      bufsize += BUFSIZE;
      tokens = realloc(tokens, bufsize);

      if (tokens == NULL) {
        perror("allocation error");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, STR_DELIM);
  }

  args_lenght = position;
  tokens[position] = NULL;

  return tokens;
}

int main(void) {
  int i;
  char *line = read_line();
  char **args = split_line(line); 
  
  printf("args lenght = %d\n", args_lenght);
  
  for (i = 0; i < args_lenght; i++) {
    printf("token = %s\n", args[i]);
  }

  return 0;
}
