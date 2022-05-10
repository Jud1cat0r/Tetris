#pragma once
//Console
void sizeWindow(int width, int hight, int top, int left);
void gotoxy(int x, int y, int color);
void gotoxy(int x, int y);
void keyCode();

//Menu
//void newGame();
void options(int x, int y);
void blackMenu();
void blackOptions();
void menu(int speed, int x, int y);

//Tetris
//void newGame();
void shaowBorderField(int x, int y);
void score(int x, int y);
void screen(int** field, int** buf);
bool move(int** field, int** buf);
void start(int speed);
int** moveKey(int** field, int** buf, int speed);
bool check(int** field, int** buf);
void checkLine(int** buf);