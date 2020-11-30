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
    // Настройка консоли и прочего
    // Выбор русской кодировки
    setlocale(LC_ALL, "Russian");
    // Цвет консоли
    system("color 00");
    // Размер консоли
    system("mode con cols=80 lines=21");
    // Невидимый курсор
    CONSOLE_CURSOR_INFO curs = { 0 };
    curs.dwSize = sizeof(curs);
    curs.bVisible = FALSE;
    ::SetConsoleCursorInfo(::GetStdHandle(STD_OUTPUT_HANDLE), &curs);
}

bool controls(spaceship &ship) {
    if (_kbhit()) {
        char ch = _getch();
        switch ((int)ch) {
        case 27:
            return false;
        case 72:
            if (ship.y > 0)
                ship.y--;
            break;
        case 80:
            if (ship.y < 15)
                ship.y++;
            break;
        }
    }
    return true;
}

int main()
{
    sys_init();
    pixel canvas[game_window_height][game_window_width];
    spaceship ship;
    init_layers(canvas);
    while (true) {
        Sleep(1000 / fps);
        update_layers(canvas, ship);
        if (!controls(ship))
            break;
    }
    return 0;
}
