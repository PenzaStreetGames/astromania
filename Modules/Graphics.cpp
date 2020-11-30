#include <windows.h>
#include <vector>
#include <map>
#include <string>

#include "Modules/Constants.h"
#include "GraphicsParts/Stars.cpp"

using namespace std;

map<string, int> colors{
    {"Black", 0},
    {"Blue", 1},
    {"Green", 2},
    {"Cyan", 3},
    {"Red", 4},
    {"Magenta", 5},
    {"Brown", 6},
    {"LightGray", 7},
    {"DarkGray", 8},
    {"LightBlue", 9},
    {"LightGreen", 10},
    {"LightCyan", 11},
    {"LightRed", 12},
    {"LightMagenta", 13},
    {"Yellow", 14},
    {"White", 15}
};

string spaceship_sprite = "\
 [#\\-    \
-}###\\   \
 [##o###>\
-}###/   \
 [#/-     ";

int spaceship_colors[5][9] = {
    {0, 15, 15, 15, 15, 0, 0, 0, 0},
    {15, 15, 15, 15, 15, 15, 0, 0, 0},
    {0, 15, 15, 15, 14, 15, 15, 15, 15},
    {15, 15, 15, 15, 15, 15, 0, 0, 0},
    {0, 15, 15, 15, 15, 0, 0, 0, 0}
};

pixel stars[game_window_height][game_window_width];

void draw_layer(pixel(&canvas)[game_window_height][game_window_width],
    pixel(&layer)[game_window_height][game_window_width]) {
    for (int i = 0; i < game_window_height; i++) {
        for (int j = 0; j < game_window_width; j++) {
            if (layer[i][j].symbol != ' ') {
                canvas[i][j] = layer[i][j];
            }
        }
    }
}

void draw_and_clear_field(pixel(&canvas)[game_window_height][game_window_width]) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = 0; coord.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    int last_color = 0, last_background = 0;
    for (int i = 0; i < game_window_height; i++) {
        for (int j = 0; j < game_window_width; j++) {
            if (canvas[i][j].color != last_color || canvas[i][j].background != last_background) {
                SetConsoleTextAttribute(hConsole, (WORD)(canvas[i][j].background << 4) | canvas[i][j].color);
                last_color = canvas[i][j].color;
                last_background = canvas[i][j].background;
            }
            cout << canvas[i][j].symbol;
            canvas[i][j].symbol = ' ';
        }
        cout << endl;
    }
    SetConsoleTextAttribute(hConsole, (WORD)(colors["Black"] << 4) | colors["White"]);
}

void draw_spaceship(pixel(&canvas)[game_window_height][game_window_width], spaceship &ship) {
    int x = ship.x, y = ship.y;
    for (int i = 0; i < ship.y_size; i++) {
        for (int j = 0; j < ship.x_size; j++) {
            char ch = spaceship_sprite[i * ship.x_size + j];
            if (ch != ' ') {
                canvas[y + i][x + j].symbol = spaceship_sprite[i * ship.x_size + j];
                canvas[y + i][x + j].color = spaceship_colors[i][j];
            }
        }
    }
}

void update_layers(pixel(&canvas)[game_window_height][game_window_width], spaceship &ship) {
    shift_sky(stars);
    draw_layer(canvas, stars);
    draw_spaceship(canvas, ship);
    draw_and_clear_field(canvas);
}

void init_layers(pixel(&canvas)[game_window_height][game_window_width]) {
    create_sky(stars);
}
