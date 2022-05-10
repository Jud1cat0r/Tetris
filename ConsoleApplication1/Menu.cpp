#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "GlobalSet.h"
#include "Prototype.h"

using namespace std;
int speed;


void options(int x = xb, int y = yb) 
{
    int key;
    system("cls");
    gotoxy(x - 13, y);
    cout << "Choose speed:";
    while (true) {
        blackOptions();
        gotoxy(x, y, Green);
        if (y == yb) cout << "Low speed";
        else if (y == yb + 2) cout << "Medium speed";
        else if (y == yb + 4) cout << "High speed";
        key = _getch();
        switch (key) {
        case 80:
            y += 2;
            break;
        case 72:
            y -= 2;
            break;
        case 27:
            menu(speed, xb, yb);
        case 13:
            if (y == yb) menu(150, xb, yb);
            else if (y == yb + 2) menu(100, xb, yb);
            else if (y == yb + 4) menu(50, xb, yb);
        }
        if (y < yb) y += 6;
        else if (y > yb + 4) y -= 6;
    }
}


void menu(int speed = 0, int x = xb, int y = yb)
{
    system("cls");
    int key;
    while (true) {
        blackMenu();
        gotoxy(x, y, Green);
        if (y == yb) cout << "NEW GAME";
        else if (y == yb + 2) cout << "OPTIONS";
        else if (y == yb + 4) cout << "EXIT";
        key = _getch();
        switch (key) {
        case 80:
            y += 2;
            break;
        case 72:
            y -= 2;
            break;
        case 27:
            exit(0);
        case 13:
            if (y == yb) start(speed);
            else if (y == yb + 2) options(xb, yb);
            else if (y == yb + 4) exit(0);
        }
        if (y < yb) y += 6;
        else if (y > yb + 4) y -= 6;

    }
}

void blackMenu() 
{
    int x = xb;
    int y = yb;
    gotoxy(x, y);
    cout << "NEW GAME";
    y += 2;
    gotoxy(x, y);
    cout << "OPTIONS";
    y += 2;
    gotoxy(x, y);
    cout << "EXIT";
}

void blackOptions()
{
    int x = xb;
    int y = yb;
    gotoxy(x, y);
    cout << "Low speed";
    y += 2;
    gotoxy(x, y);
    cout << "Medium speed";
    y += 2;
    gotoxy(x, y);
    cout << "High speed";
}
