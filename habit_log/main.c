#include <stdio.h>
#include <string.h>

#include "commands/command.h"
#include "flags/flags.h"

int main(int argc, char *argv[]) {
  if (is_flag(argv[1]) == 1) {
    flag_struct flag;

    flag.flag = flag_value(argv[1]);
    strcpy(flag.param, argv[2]);

    printf("is a flag\n");

    execute_flag(flag);
  } else {
    command_struct command;

    printf("is a command\n");

    command.command = command_value(argv[1]);
    command.flag = not_flag;
    strcpy(command.param, argv[2]);
    
    execute_command(command);
  }

  return 0;
}
