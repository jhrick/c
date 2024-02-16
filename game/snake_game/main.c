#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

#define WIDTH 20
#define HEIGHT 40

struct snake_positions {
    int x;
    int y;
};

struct snake_positions snake(int x, int y) {
    struct snake_positions snake_positions_obj;

    snake_positions_obj.x = x;
    snake_positions_obj.y = y;

    return snake_positions_obj;
}

void game_panel(struct snake_positions snake_positions_obj) {
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
    struct snake_positions snake_ps;

    x = y = 0;

    initscr();
    keypad(stdscr, true);
    while (1) {
        ch = getch();
        mvprintw(0, 0, "\033[H\033[J"); /* clear screen */

        switch (ch)  {
            case KEY_UP: 
                --x;
                printw("\nup\n%d\n", x);
                break;
            case KEY_DOWN: 
                ++x;
                printw("\ndown\n%d\n", x);
                break;
            case KEY_LEFT: 
                --y;
                printw("\nleft\n%d\n", y);
                break;
            case KEY_RIGHT: 
                ++y;
                printw("\nright\n%d\n", y);
                break;
        }      

        snake_ps = snake(x, y);

        game_panel(snake_ps);
        sleep(0.75);
    }
    endwin();
    return 0;
}