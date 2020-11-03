#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Modules/Graphics.cpp"
#include "Modules/Constants.h"

using namespace std;

int mode = 0;

int main()
{
    setlocale(LC_ALL, "Russian");
    char ch;
    while (true) {
        Sleep(1000 / fps);
        COORD coord;
        coord.X = 0; coord.Y = 0;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        draw_field();
        if (_kbhit()) {
            char ch = _getch();
            cout << ch;
            if ((int)ch == 27)
                break;
        }
    }   
}
