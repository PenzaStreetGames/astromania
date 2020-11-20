#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>

#include "Modules/Graphics.cpp"
#include "Modules/Constants.h"
#include "Modules/Pixel.h"
#include <clocale>

using namespace std;

int mode = 0;

void sys_init() {
    setlocale(LC_ALL, "Russian");
    system("color 00");
    system("mode con cols=80 lines=21");
    CONSOLE_CURSOR_INFO curs = { 0 };
    curs.dwSize = sizeof(curs);
    curs.bVisible = FALSE;
    ::SetConsoleCursorInfo(::GetStdHandle(STD_OUTPUT_HANDLE), &curs);
}

int main()
{
    sys_init();
    pixel canvas[game_window_height][game_window_width];
    pixel stars[game_window_height][game_window_width];
    init_layers(canvas);
    while (true) {
        Sleep(1000 / fps);
        update_layers(canvas);
        if (_kbhit()) {
            char ch = _getch();
            cout << ch;
            if ((int)ch == 27)
                break;
        }
    }
    return 0;
}
