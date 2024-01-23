#ifndef FLAGS_H
#define FLAGS_H

typedef enum  {
  create = 1,
  exclude,
} commands;

void remove_dash();

commands get_command_value();

void execute_flag();

#endif
