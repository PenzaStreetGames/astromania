#include "Modules/Constants.h"

using namespace std;

void draw_field() {
    for (int i = 0; i < game_window_height; i++) {
        for (int j = 0; j < game_window_width; j++) {
            cout << (rand() < 1024 ? "*" : " ");
        }
        cout << endl;
    }
}