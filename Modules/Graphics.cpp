#include <windows.h>
#include <vector>
#include <map>

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

void draw_field(pixel(&canvas)[game_window_height][game_window_width]) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = 0; coord.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    for (int i = 0; i < game_window_height; i++) {
        for (int j = 0; j < game_window_width; j++) {
            SetConsoleTextAttribute(hConsole, (WORD)(canvas[i][j].background << 4) | canvas[i][j].color);
            cout << canvas[i][j].symbol;
        }
        cout << endl;
    }
    SetConsoleTextAttribute(hConsole, (WORD)(colors["Black"] << 4) | colors["White"]);
}

void clear_canvas(pixel(&canvas)[game_window_height][game_window_width]) {
    for (int i = 0; i < game_window_height; i++) {
        for (int j = 0; j < game_window_width; j++) {
            canvas[i][j].symbol = ' ';
        }
    }
}

void update_layers(pixel(&canvas)[game_window_height][game_window_width]) {
    clear_canvas(canvas);
    shift_sky(stars);
    draw_layer(canvas, stars);
    draw_field(canvas);
}

void init_layers(pixel(&canvas)[game_window_height][game_window_width]) {
    create_sky(stars);
}
