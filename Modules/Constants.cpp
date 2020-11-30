#include <string>

int const fps = 50;
int const game_window_width = 80;
int const game_window_height = 20;

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

struct pixel {
    char symbol;
    int color;
    int background;
};

struct spaceship {
    int x = 1;
    int y = 0;
    int x_size = 9;
    int y_size = 5;
};

int stars_sparsity = 32;
int stars_diversity = 16;
long int frame = 0;
