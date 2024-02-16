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


// void key_listener(int * snake_positions) {
//     if (getch() == '\033') {
//         getch();
//         switch (getch()) {
//         case 'A':
//             *(snake_positions + 1) - 1;
//             break;
//         case 'B':
//             *(snake_positions + 1) + 1;
//             break;
//         case 'C':
//             *snake_positions + 1;
//             break;
//         case 'D':
//             *snake_positions - 1;
//             break;
//         }
//     }
// }

struct snake_positions snake(int x, int y) {
    struct snake_positions snake_positions_obj;

    snake_positions_obj.x = x;
    snake_positions_obj.y = y;

    return snake_positions_obj;
}

void game_panel(char ch, struct snake_positions snake_positions_obj) {
    int snake_x_position, snake_y_position;

    snake_x_position = snake_positions_obj.x;
    snake_y_position = snake_positions_obj.y;

    printf("x: %d, y: %d\n", snake_x_position, snake_y_position);

    for (int width = 0; width <= WIDTH; width++) {
        for (int height = 0; height <= HEIGHT; height++) {
            if (width == snake_x_position && height == snake_y_position) {
                printf("# ");
            } else {
                printf("%c ", ch);
            }
        }
        printf("\n");
    }
}

int main() {
    printf("\x1b[2J");

    struct snake_positions snake_ps = snake(0, 0);

    while (1) {
        // key_listener(player);

        printf("\033[H\033[J");
        game_panel('.', snake_ps);
        sleep(1);
        // printf("\033[%d;%dH", 0, 0);
        // game_panel('.', player);
        // sleep(1);
    }

    printf("\x1b[H");

    return 0;
}