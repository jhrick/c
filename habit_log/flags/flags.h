#ifndef FLAGS_H
#define FLAGS_H

typedef enum  {
  show = 1,
  help,
  nl = 0,
} flags;

void remove_dash();

flags flag_value();

#endif
