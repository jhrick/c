#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

enum { BUFSIZE = 1028 };

const char DELIM[] = " \t\r\n\a";

char *read_line() {
  int c, i;
  int bufsize = BUFSIZE;
  char *line = malloc(sizeof(char) * bufsize);

  if (line == NULL) {
    printf("allocation error\n");
    exit(EXIT_FAILURE);
  }
  
  i = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      break;
    }

    line[i] = c;

    if (i >= bufsize) {
      bufsize += BUFSIZE;
      line = realloc(line, sizeof(char) * bufsize);

      if (line == NULL) {
        printf("allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    i++;
  }

  line[i] = '\0';

  return line;
}

char **split_line(char *line) {
  int position, bufsize = BUFSIZE;
  char *token;
  char **tokens = malloc(sizeof(char *) * bufsize);

  if (tokens == NULL) {
    printf("allocation error");
    exit(EXIT_FAILURE);
  }

  position = 0;

  token = strtok(line, DELIM);
  while (token) {
    tokens[position] = token;

    if (position > bufsize) {
      bufsize += BUFSIZE;
      tokens = realloc(tokens, sizeof(char *) * bufsize);

      if (tokens == NULL) {
        printf("allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    position++;

    token = strtok(NULL, DELIM);
  }

  return tokens;
}

int launch(char **args) {
  pid_t pid;
  int status;

  pid = fork();

  if (pid == 0) {
    if (execvp(args[0], args) == -1) {
      perror("deu erro");
    } 

    exit(EXIT_FAILURE);
  } else {
    do {
      waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}

void execute() {
  char *line;
  char **args;
  int status;

  do {
    printf("-> ");

    line = read_line();
    args = split_line(line);
    status = launch(args);

    free(line);
    free(args);
  } while (status); 
}

int main(void) {
  execute();

  return 0;
}
