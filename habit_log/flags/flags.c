#include <stdio.h>
#include <string.h>

#include "flags.h"
#include "../commands/command.h"

flags flag_value(char *command_string) {
  if (strcmp(command_string, "-show") == 0) {
    return show;
  } else if (strcmp(command_string, "-help") == 0) {
    return help;
  } else {
    return nl;
  }
}
