#include <stdio.h>
#include <string.h>

#include "commands/command.h"
#include "flags/flags.h"

int main(int argc, char *argv[]) {
  command_struct command;

  command.command = command_value(argv[1]);
  command.flag = nl;
  strcpy(command.param, argv[2]);

  printf("%d\n", command.command);

  execute_command(command);

  return 0;
}
