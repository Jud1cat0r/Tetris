#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "GlobalSet.h"
#include "Prototype.h"

using namespace std;


void sizeWindow(int width = 500, int hight = 500, int top = 0, int left = 0) {
    HWND hWindowConsole = GetConsoleWindow();
    MoveWindow(hWindowConsole, top, left, width, hight, true);
}


void gotoxy(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hConsole, coord);
    SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Black));

}


void gotoxy(int x, int y, int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hConsole, coord);
    SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | color));
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 99;
    cci.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cci);
}


void keyCode() {
    int key;
    do {
        gotoxy(0, 0);
        key = _getch();
        cout << "keyCode: " << key << "  ";

    } while (key != 13);

}
