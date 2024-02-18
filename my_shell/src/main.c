#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MY_SH_RL_BUFSIZE 1024
#define MY_SH_TOK_BUFSIZE 64
#define MY_TOK_DELIM " \t\r\n\a"

/*
    Functions declarations for builtin shell commands:
*/
int my_sh_cd(char **args);
int my_sh_help(char **args);
int my_sh_exit(char **args);

/*
    List of builtin commnads, followed by their corresponding functions.
*/
char * builtin_str[] = {
    "cd",
    "help",
    "exit"
};

int (*builtin_func[]) (char **) = {
    &my_sh_cd,
    &my_sh_help,
    &my_sh_exit
};

int my_sh_num_builtins() {
    return sizeof(builtin_str) / sizeof(char *);
}

int my_sh_cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "my_sh: expect argument to \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("my_sh");
        }
    }
    return 1;
}

int my_sh_help(char **args) {
    int i;
    printf("Jorge Henrique's MY_SH\n");
    printf("Type program names and arguments, and hit enter.\n");
    printf("The following are built in:\n");

    for (i = 0; i < my_sh_num_builtins(); i++) {
        printf("  %s\n", builtin_str[i]);
    }

    printf("Use the man command for information on other programs.\n");
    return 1;
}

int my_sh_exit(char **args) {
    return 0;
}

char *my_sh_read_line(void) {
    int bufsize = MY_SH_RL_BUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    if (!buffer) {
        fprintf(stderr, "my_sh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        c = getchar();

        if (c == EOF || c == '\n') {
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position] = c;
        }
        position++;

        if (position >= bufsize) {
            bufsize += MY_SH_RL_BUFSIZE;
            buffer = realloc(buffer, bufsize);
            if (!buffer) {
                fprintf(stderr, "my_sh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

char **my_sh_split_line(char *line) {
    int bufsize = MY_SH_TOK_BUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    if (!tokens) {
        fprintf(stderr, "my_sh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, MY_TOK_DELIM);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += MY_SH_TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens) {
                fprintf(stderr, "my_sh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, MY_TOK_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

int my_sh_launch(char **args) {
    __pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        // child process
        if (execvp(args[0], args) == -1) {
            perror("my_sh");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // error forking
        perror("my_sh");
    } else {
        // parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

int my_sh_execute(char **args) {
    int i;

    if (args[0] == NULL) {
        return 1;
    }

    for (i = 0; i < my_sh_num_builtins(); i++) {
        if (strcmp(args[0], builtin_str[i]) == 0) {
            return (*builtin_func[i])(args);
        }
    }
    return my_sh_launch(args);
}

void my_sh_loop(void) {
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = my_sh_read_line();
        args = my_sh_split_line(line);
        status = my_sh_execute(args);

        free(line);
        free(args);
    } while (status);
}

int main(int argc, char *argv[]) {
    
    my_sh_loop();

    return EXIT_SUCCESS;
}