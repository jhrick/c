#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

#define WIDTH 20
#define HEIGHT 40

enum directions {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct snake_struct {
    int x;
    int y;
};

struct apple_struct {
    int x;
    int y;
};


struct snake_struct snake_initialize(int x, int y) {
    struct snake_struct snake_positions_obj;

    snake_positions_obj.x = x;
    snake_positions_obj.y = y;

    return snake_positions_obj;
}

struct apple_struct generate_apple() {
    struct apple_struct apple;
    int r = rand();
    
    apple.x = r % WIDTH;
    apple.y = r % HEIGHT;

    return apple;
}

bool snake_eat_apple(struct snake_struct snake, struct apple_struct apple) {
    if (snake.x == apple.x && snake.y == apple.y) {
        return 1;
    }

    return 0;
}

enum directions key_handler(int arrow) {
    enum directions direction;

    switch (arrow)  {
            case KEY_UP: 
                direction = UP;
                printw("\nup\n%");
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

void game_panel(struct snake_struct snake_positions_obj, struct apple_struct apple) {
    int snake_x_position, snake_y_position;

    snake_x_position = snake_positions_obj.x;
    snake_y_position = snake_positions_obj.y;

    printw("x: %d, y: %d\n\n", snake_x_position, snake_y_position);
    printw("apple: %d %d\n", apple.x, apple.y);

    for (int width = 0; width <= WIDTH; width++) {
        for (int height = 0; height < HEIGHT; height++) {
            if (width == snake_x_position && height == snake_y_position) {
                printw("# ");
            } else if (width == apple.x && height == apple.y) {
                printw("* ");
            } else {
                printw(". ");
            }
        }
        printw(". \n");
    }
}

int main(void) {
    int ch;
    int x, y;
    enum directions direction;
    struct snake_struct snake;
    struct apple_struct apple;

    x = y = 0;
    direction = RIGHT;
    apple = generate_apple();

    initscr();
    keypad(stdscr, true);
    nodelay(stdscr, TRUE);
    while (1) {
        ch = getch();

        timeout(50);

        if ((ch = getch()) == ERR) {
            switch (direction) {
            case UP:
                --x;
                printw("cima\n");
                break;
            case DOWN: 
                ++x;
                printw("baixo\n");
                break;
            case LEFT: 
                --y;
                printw("esquerda\n");
                break;
            case RIGHT: 
                ++y;
                printw("direita\n");
                break;
            default:
                ++y;
            }
        } else {
            direction = key_handler(ch);
        }

        if (snake_eat_apple(snake, apple)) {
            apple = generate_apple();
        }

        mvprintw(0, 0, "\033[H\033[J"); /* clear screen */

        snake = snake_initialize(x, y);

        game_panel(snake, apple);
    }
    endwin();
    return 0;
}