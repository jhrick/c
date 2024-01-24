#include <stdio.h>
#include <string.h>

#include "flags.h"
#include "../commands/command.h"

int is_flag(char arg[]) {
  if (arg[0] == '-') {
    return 1;
  } else {
    return 0;
  }
}

flags flag_value(char *command_string) {
  if (strcmp(command_string, "-show") == 0) {
    return show;
  } else if (strcmp(command_string, "-help") == 0) {
    return help;
  } else {
    return not_flag;
  }
}

void execute_flag(flag_struct flag) {
  printf("executing flag...");
}