#ifndef COMMAND_H
#define COMMAND_H

#include "../flags/flags.h"

typedef enum {
  create = 1,
  config,
  null = 0,
} commands;

typedef struct {
  commands command;
  flags flag;
  char param[7];
} command_struct;

commands command_value();

void execute_command();

#endif // DEBUG
