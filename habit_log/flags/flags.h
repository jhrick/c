#ifndef FLAGS_H
#define FLAGS_H

typedef enum  {
  show = 1,
  help,
  not_flag = 0,
} flags;

typedef struct {
  flags flag;
  char param[10];
} flag_struct;

int is_flag();

flags flag_value();

void execute_flag();

#endif
