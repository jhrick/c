#include <stdio.h>
#include <string.h>
#include "flags.h"

void remove_dash(char *flag) {
  if (flag[0] == '-') {
    for (int i = 0; flag[i] != '\0'; i++) {
      flag[i] = flag[i + 1];
    }
  }
}

commands get_command_value(char *command_string) {
  if (strcmp(command_string, "create") == 0) {
    return create;
  } else if (strcmp(command_string, "exclude") == 0) {
    return exclude;
  } else {
    printf("command (%s) not found\n", command_string);
  }
}

void execute_flag(char flag[]) {
  remove_dash(flag);

  commands command = get_command_value(flag);
  
  printf("%d\n", command);

  switch (command) {
    case 1: {
      printf("creating...\n");
      break;
    }
    case 2: {
      printf("deleting...\n");
      break;
    }
    default: printf("flag -%s not found\n", flag);
  }
}
