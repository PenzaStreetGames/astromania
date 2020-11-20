#include "Modules/Constants.h"


void create_sky(pixel(&stars)[game_window_height][game_window_width]) {
    for (int i = 0; i < game_window_height; i++) {
        for (int j = 0; j < game_window_width; j++) {
            if (rand() % stars_sparsity == 0) {
                int chance = rand() % stars_diversity, color;
                if (chance < stars_diversity * 0.2)
                    color = 7;
                else
                    color = 8;
                stars[i][j].symbol = '*';
                stars[i][j].color = color;
            }
            else {
                stars[i][j].symbol = ' ';
            }
        }
    }
}

void shift_sky(pixel(&stars)[game_window_height][game_window_width]) {
    for (int j = 1; j < game_window_width; j++) {
        for (int i = 0; i < game_window_height; i++) {
            stars[i][j - 1] = stars[i][j];
        }
    }
    for (int i = 0; i < game_window_height; i++) {
        int j = game_window_width - 1;
        if (rand() % stars_sparsity == 0) {
            int chance = rand() % stars_diversity, color;
            if (chance < stars_diversity * 0.2)
                color = 7;
            else
                color = 8;
            stars[i][j].symbol = '*';
            stars[i][j].color = color;
        }
        else {
            stars[i][j].symbol = ' ';
        }
    }
}