#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 10
#define HEIGHT 30

#define X_POSITION 0
#define Y_POSITION 1
#define INITIAL_POSITION 0
#define SPEED 1

#define MAX_SNAKE_SIZE 10 * 30
#define POSTIONS 2
#define SNAKE_HEAD 0

enum directions { UP, DOWN, LEFT, RIGHT };

struct snake_schema {
  int lenght;
  int body[MAX_SNAKE_SIZE][POSTIONS];
};

struct apple_schema {
  int x;
  int y;
};

enum directions last_direction;
struct snake_schema snake;
int snake_lenght;
int snake_head_positions[POSTIONS]; // x and y position

void snake_moviment(enum directions direction) {
  int i;

  for (i = (snake_lenght - 1); i > 0; i--) {
    snake.body[i][X_POSITION] = (snake.body[i - 1][X_POSITION]);
    snake.body[i][Y_POSITION] = (snake.body[i - 1][Y_POSITION]);
  }

  switch (direction) {
  case UP:
    if (last_direction != DOWN) {
      snake_head_positions[X_POSITION]--;
      snake.body[SNAKE_HEAD][X_POSITION] = snake_head_positions[X_POSITION];
    }
    last_direction = UP;
    break;
  case DOWN:
    if (last_direction != UP) {
      snake_head_positions[X_POSITION]++;
      snake.body[SNAKE_HEAD][X_POSITION] = snake_head_positions[X_POSITION];
    }
    last_direction = DOWN;
    break;
  case LEFT:
    if (last_direction != RIGHT) {
      snake_head_positions[Y_POSITION]--;
      snake.body[SNAKE_HEAD][Y_POSITION] = snake_head_positions[Y_POSITION];
    }
    last_direction = LEFT;
    break;
  case RIGHT:
    if (last_direction != LEFT) {
      snake_head_positions[Y_POSITION]++;
      snake.body[SNAKE_HEAD][Y_POSITION] = snake_head_positions[Y_POSITION];
    }
    last_direction = RIGHT;
    break;
  }
}

struct snake_schema snake_initialize(void) {
  int i;
  struct snake_schema snake;

  snake.body[SNAKE_HEAD][X_POSITION] = INITIAL_POSITION;
  snake.body[SNAKE_HEAD][Y_POSITION] = INITIAL_POSITION;

  snake.body[1][X_POSITION] = (snake.body[SNAKE_HEAD][X_POSITION] - 1);
  snake.body[1][Y_POSITION] = (snake.body[SNAKE_HEAD][Y_POSITION] - 1);

  return snake;
}

struct apple_schema generate_apple() {
  struct apple_schema apple;
  int r = rand();

  apple.x = r % WIDTH;
  apple.y = r % HEIGHT;

  return apple;
}

bool snake_eat_apple(struct apple_schema apple) {
  if (snake.body[SNAKE_HEAD][X_POSITION] == apple.x &&
      snake.body[SNAKE_HEAD][Y_POSITION] == apple.y) {
    return 1;
  }

  return 0;
}

enum directions key_handler(int arrow) {
  enum directions direction;

  switch (arrow) {
  case KEY_UP:
    direction = UP;
    break;
  case KEY_DOWN:
    direction = DOWN;
    break;
  case KEY_LEFT:
    direction = LEFT;
    break;
  case KEY_RIGHT:
    direction = RIGHT;
    break;
  }

  return direction;
}

int render_snake(int width, int height) {
  int i;

  for (i = 0; i < snake_lenght; i++) {
    if (snake.body[i][X_POSITION] == width &&
        snake.body[i][Y_POSITION] == height) {
      printw(" # ");
      return 1;
    }
  }

  return 0;
}

void game_panel(struct apple_schema apple) {
  int width, height;

  clear();

  for (width = 0; width < WIDTH; width++) {
    for (height = 0; height < HEIGHT; height++) {
      if (render_snake(width, height)) {
        continue;
      } else if (apple.x == width && apple.y == height) {
        printw(" * ");
      } else {
        printw(" . ");
      }
    }
    printw("\n");
  }
  refresh();
}

int main(void) {
  int ch;

  enum directions direction;
  struct apple_schema apple;
  
  snake_head_positions[X_POSITION] = snake_head_positions[Y_POSITION] = INITIAL_POSITION;

  snake_lenght = 3;

  last_direction = RIGHT;
  direction = RIGHT;

  apple = generate_apple();
  snake = snake_initialize();

  initscr();
  keypad(stdscr, true);
  nodelay(stdscr, TRUE);

  while (1) {
    ch = getch();

    timeout(150);

    if ((ch = getch()) != ERR) {
      direction = key_handler(ch);
    }

    mvprintw(0, 0, "\033[H\033[J"); /* clear screen */
    
    snake_moviment(direction);

    if (snake_eat_apple(apple)) {
      apple = generate_apple();
      snake_lenght++;
    }

    game_panel(apple);
  }
  endwin();
  return 0;
}
