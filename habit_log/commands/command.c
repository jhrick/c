#include <stdio.h>
#include <string.h>

#include "command.h"

commands command_value(char *command_str) {
  if (strcmp(command_str, "create") == 0) {
    return create;
  } else if (strcmp(command_str, "config") == 0) {
    return config;
  } else {
    return null;
  }
}

void execute_command(command_struct command) {
  switch (command.command) {
    case 1: {
      printf("creating...\n");
      break;
    }
    case 2: {
      printf("settings...\n");
      break;
    }
    default: printf("'%s' is not a habit_log command\n");
  }
}
