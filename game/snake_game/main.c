#include <stdio.h>
#include <unistd.h>

#define WIDTH 20
#define HEIGHT 40

// int *snake(int x, int y) {
//     int x_position, y_position;
//     int *positions_pointer;

//     positions_pointer = &x_position;

//     x_position = x;
//     y_position = y;

//     return positions_pointer;
// }

void game_panel(char ch) {
    // int snake_x_position, snake_y_position;

    // int *snake_positions = snake(20, 40);

    // snake_x_position = *snake_positions;
    // snake_y_position = *(snake_positions + 1);

    // printf("x: %d, y: %d\n", snake_x_position, snake_y_position);

    for (int width = 0; width <= WIDTH; width++) {
        for (int height = 0; height <= HEIGHT; height++) {
            // if (width == snake_x_position && height == snake_y_position) {
            //     printf("# ");
            // } else {
                printf("%c ", ch);
            // }
        }
        printf("\n");
    }
}

int main() {
    printf("\x1b[2J");

    while (1) {
        printf("\033[H\033[J");
        game_panel('.');
        sleep(1);
        printf("\033[%d;%dH", 0, 0);
        game_panel('.');
        sleep(1);
    }

    printf("\x1b[H");

    return 0;
}