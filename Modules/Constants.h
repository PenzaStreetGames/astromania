#pragma once

int const fps = 20;
int const game_window_width = 80;
int const game_window_height = 20;
struct pixel {
    char symbol = ' ';
    int color = 15;
    int background = 0;
};

int stars_sparsity = 32;
int stars_diversity = 16;
long int frame = 0;