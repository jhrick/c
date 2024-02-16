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

struct snake_struct snake_initialize(int x, int y) {
    struct snake_struct snake_positions_obj;

    snake_positions_obj.x = x;
    snake_positions_obj.y = y;

    return snake_positions_obj;
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

void game_panel(struct snake_struct snake_positions_obj) {
    int snake_x_position, snake_y_position;

    snake_x_position = snake_positions_obj.x;
    snake_y_position = snake_positions_obj.y;

    printw("x: %d, y: %d\n\n", snake_x_position, snake_y_position);

    for (int width = 0; width <= WIDTH; width++) {
        for (int height = 0; height < HEIGHT; height++) {
            if (width == snake_x_position && height == snake_y_position) {
                printw("# ");
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
    int random_num = 0;

    x = y = 0;
    direction = RIGHT;

    initscr();
    keypad(stdscr, true);
    nodelay(stdscr, TRUE);
    while (1) {
        ch = getch();

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
        mvprintw(0, 0, "\033[H\033[J"); /* clear screen */

        snake = snake_initialize(x, y);

        game_panel(snake);
        timeout(80);
    }
    endwin();
    return 0;
}