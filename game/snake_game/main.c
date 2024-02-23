// #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

#define WIDTH 10
#define HEIGHT 30
#define X_POSITION 0
#define Y_POSITION 1
#define MAX_SNAKE_SIZE 10 * 30
#define POSTIONS 2
#define SNAKE_HEAD 1
#define SNAKE_FIRST_BODY_PART 1

enum directions {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct snake_schema {
    int lenght;
    int head[POSTIONS];
    int body[MAX_SNAKE_SIZE][POSTIONS];
};

struct apple_schema {
    int x;
    int y;
};

void snake_moviment(enum directions direction);

enum directions last_direction;
int snake_lenght;
int snake_head_positions[POSTIONS]; // x and y position

struct snake_schema snake_initialize() {
  int i;  
  struct snake_schema snake;

  snake.head[X_POSITION] = snake_head_positions[X_POSITION];
  snake.head[Y_POSITION] = snake_head_positions[Y_POSITION];

  for (i = 0; i < snake_lenght; i++) {
    snake.body[i][X_POSITION] = (snake.head[X_POSITION] - i);
    snake.body[i][Y_POSITION] = (snake.head[Y_POSITION] - i);
  }

  return snake;
}

struct apple_schema generate_apple() {
    struct apple_schema apple;
    int r = rand();
    
    apple.x = r % WIDTH;
    apple.y = r % HEIGHT;

    return apple;
}

bool snake_eat_apple(struct snake_schema snake, struct apple_schema apple) {
  if (snake.head[X_POSITION] == apple.x && snake.head[Y_POSITION] == apple.y) {
      return 1;
  }

  return 0;
}

enum directions key_handler(int arrow) {
  enum directions direction;

  switch (arrow)  {
    case KEY_UP: 
      direction = UP;
      printw("\nup\n");
      break;
    case KEY_DOWN: 
      direction = DOWN;
      printw("\ndown\n");
      break;
    case KEY_LEFT: 
      direction = LEFT;
      printw("\nleft\n");
      break;
    case KEY_RIGHT: 
      direction = RIGHT;
      printw("\nright\n");
      break;
  } 

  return direction;
}

void game_panel(struct snake_schema snake, struct apple_schema apple) {
  int i;
  int width, height;

  printw("x: %d, y: %d\n\n", snake.head[X_POSITION], snake.head[Y_POSITION]);
  printw("apple: %d %d\n", apple.x, apple.y);

  for (width = 0; width <= WIDTH; width++) {
    i = 0;
    for (height = 0; height < HEIGHT; height++) {
      if (snake.head[X_POSITION] == width && snake.head[Y_POSITION] == height) {
        printw("# ");
      } else if (apple.x == width && apple.y == height) {
        printw("* ");
      } else {
        printw(". ");
      }
    }
    printw("\n");
  }
}

int main(void) {
  int ch;

  struct snake_schema snake;
  enum directions direction;
  struct apple_schema apple;

  snake_lenght = 3;

  last_direction = RIGHT;
  direction = RIGHT;

  apple = generate_apple();

  initscr();
  keypad(stdscr, true);
  nodelay(stdscr, TRUE);

  while (1) {
    printw("lenght: %d | ", snake_lenght);
    ch = getch();

    timeout(50);

    if ((ch = getch()) == ERR) {
      snake_moviment(direction);
    } else {
      direction = key_handler(ch);
    }

    mvprintw(0, 0, "\033[H\033[J"); /* clear screen */

    snake = snake_initialize();

    if (snake_eat_apple(snake, apple)) {
      apple = generate_apple();
      snake_lenght++;
    }

    game_panel(snake, apple);
  }
  endwin();
  return 0;
}

void snake_moviment(enum directions direction) {
  switch (direction) {
    case UP:
      if (last_direction != DOWN) snake_head_positions[X_POSITION]--;
      last_direction = UP;
      break;
    case DOWN:
      if (last_direction != UP) snake_head_positions[X_POSITION]++;
      last_direction = DOWN;
      break;
    case LEFT:
      if (last_direction != RIGHT) snake_head_positions[Y_POSITION]--;
      last_direction = LEFT;
      break;
    case RIGHT:
      if (last_direction != LEFT) snake_head_positions[Y_POSITION]++;
      last_direction = RIGHT;
      break;
  }
}
