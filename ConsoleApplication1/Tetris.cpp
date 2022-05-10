#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include "GlobalSet.h"
#include "Prototype.h"

using namespace std;

int nextfigure;
int points;
int sp;

int figure[4][4];// �������� ������� ��� ������

int initfigure[7][4][4] = //������������� ����� �������
{
    {{1, 1, 0, 0},
     {1, 1, 0, 0},
     {0, 0, 0, 0},
     {0, 0, 0, 0}},

    {{1, 0, 0, 0},
     {1, 0, 0, 0},
     {1, 0, 0, 0},
     {1, 0, 0, 0}},

    {{1, 1, 0, 0},
     {0, 1, 0, 0},
     {0, 1, 0, 0},
     {0, 0, 0, 0}},

    {{1, 1, 0, 0},
     {1, 0, 0, 0},
     {1, 0, 0, 0},
     {0, 0, 0, 0}},

    {{1, 0, 0, 0},
     {1, 1, 0, 0},
     {0, 1, 0, 0},
     {0, 0, 0, 0}},

    {{0, 1, 0, 0},
     {1, 1, 0, 0},
     {1, 0, 0, 0},
     {0, 0, 0, 0}},

    {{1, 0, 0, 0},
     {1, 1, 0, 0},
     {1, 0, 0, 0},
     {0, 0, 0, 0}}
};


void screen(int** field, int** buf) //��������� �������� �������
{
    for (int i = 0, y = 2; i < n; ++i)
    {
        gotoxy(16, y);
        for (int j = 0; j < m; ++j)
        {
            if (field[i][j] == 0 && buf[i][j] == 0) cout << char(176);
            else if (field[i][j] == 1 || buf[i][j] == 1) cout << "#";
        }
        y++;
    }
}


void shaowBorderField(int x, int y)//���������� �����
{
    for (int i = 0; i < n + 2; i++)
    {
        gotoxy(x, y);
        for (int j = 0; j < m + 2; j++)
        {
            if (i == 0) cout << char(219);
            else if (i == n + 1) cout << char(219);
            else if (j == 0) cout << char(219);
            else if (j == m + 1) cout << char(219);
            else cout << " ";
        }
        y++;
    }
}


void score(int x, int y)//�������� ���� 
{
    x = x + 30;
    y = y + 3;
    gotoxy(x, y);

    cout << "score: " << points;
}

void showNextFigure(int x, int y)//�������� ��������� ������
{
    for (int i = 0; i < 4; i++)
    {
        gotoxy(x, y);
        for (int j = 0; j < 4; j++)
        {
            if (initfigure[nextfigure][i][j] == 1) cout << "#";
            else cout << " ";
        }
        y++;
        cout << endl;
    }
}

int randomFigure()
{
    return rand() % 7;
}

void createfigure() //�������� ������
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            figure[i][j] = initfigure[nextfigure][i][j];
        }
    }
    nextfigure = randomFigure();
    showNextFigure(46, 6);
}


void clearField(int** field) //������� �������
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            field[i][j] = 0;
        }
    }
}


int** moveKey(int** field, int** buf, int speed)//������� �������� � ����, ����� � ���������
{
    bool flag = true;
    if (_kbhit())
    {
        int** buf2 = new int* [n];//������������� ��� �������
        for (int i = 0; i < n; ++i)
        {
            buf2[i] = new int[m];
            for (int j = 0; j < m; ++j)
            {
                buf2[i][j] = 0;
            }
        }
        int c = _getch();
        switch (c)
        {
        case 72:
            if (nextfigure == 0) break;
            flag = false;
            int n2, m2;
            for (int i = n - 1; i >= 0; --i)//����� � ����� ������ �� i
            {
                for (int j = 0; j < m; ++j)
                {
                    if (field[i][j] == 1)
                    {
                        flag = true;
                        if (i == 1) n2 = i + 3;
                        else if (i == 2) n2 = i + 2;
                        else if (i == 3) n2 = i + 1;
                        else n2 = i;
                    }
                    if (flag == true) break;
                }
                if (flag == true) break;
            }
            flag = false;
            for (int j = 0; j < m; j++)//����� � ����� ������ �� j
            {
                for (int i = n - 1; i > 0; i--)
                {
                    if (field[i][j] == 1)
                    {
                        flag = true;
                        if (j == m - 1) m2 = j - 3;
                        else if (j == m - 2) m2 = j - 2;
                        else if (j == m - 1) m2 = j - 1;
                        else m2 = j;
                    }
                    if (flag == true) break;
                }
                if (flag == true) break;
            }

            for (int j = m2, k = n2 - 3; j <= m2 + 3; j++, k++)  //���������
            {
                for (int i = n2 - 3, l = m2 + 3; i <= n2; l--, i++)
                {
                    buf2[k][l] = field[i][j];
                }
            }
            if (check(buf, buf2)) //������ buf2 � buf
            {
                clearField(field);
                for (int i = 0; i < n; ++i) //���������� ������� ����� ��������
                {
                    for (int j = 0; j < m; ++j)
                    {
                        if (buf2[i][j] == 1) field[i][j] = buf2[i][j];
                    }
                }
            }
            break;
        case 75://�������� �����
            for (int i = n - 1; i >= 0; --i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (field[i][j] == 1)
                    {
                        if (j > 0)
                        {
                            buf2[i][j] = 0;
                            buf2[i][j - 1] = 1;
                        }
                        else
                        {
                            flag = false;
                            break;
                        }
                    }
                }
            }
            if (flag && check(buf, buf2))
            {
                clearField(field);
                for (int i = 0; i < n; ++i) //���������� ������� ����� ��������
                {
                    for (int j = 0; j < m; ++j)
                    {
                        if (buf2[i][j] == 1) field[i][j] = buf2[i][j];
                    }
                }
            }
            break;
        case 77://�������� ������
            for (int i = n - 1; i >= 0; --i)
            {
                for (int j = m; j >= 0; --j)
                {
                    if (field[i][j] == 1)
                    {
                        if (j < m - 1)
                        {
                            buf2[i][j] = 0;
                            buf2[i][j + 1] = 1;
                        }
                        else
                        {
                            flag = false;
                            break;
                        }
                    }
                }
            }
            if (flag && check(buf, buf2))
            {
                clearField(field);
                for (int i = 0; i < n; ++i) //���������� ������� ����� ��������
                {
                    for (int j = 0; j < m; ++j)
                    {
                        if (buf2[i][j] == 1) field[i][j] = buf2[i][j];
                    }
                }
            }
            break;
        case 27://esc ����� � ����
            menu(speed, xb, yb);
            break;
        case 80://�������� �������� ������ ����
            sp = 0;
            break;
        default:
            break;
        }
    }
    return field;
}


bool move(int** field, int** buf) //������� ������ ���� ���� �� ����� ��� ��� buf
{
    int** buf2 = new int* [n];//������������� ��� ������� ��� �������� ������������
    for (int i = 0; i < n; ++i)
    {
        buf2[i] = new int[m];
        for (int j = 0; j < m; ++j)
        {
            buf2[i][j] = 0;
        }
    }

    for (int i = n - 1; i >= 0; --i)//���� ������ � ������� �� �� 1 ����
    {
        for (int j = 0; j < m; ++j)
        {
            if (field[i][j] == 1)
            {
                if (i == (n - 1)) return false;
                buf2[i][j] = 0;
                buf2[i + 1][j] = 1;
            }
        }
    }

    if (check(buf, buf2))
    {
        clearField(field);
        for (int i = 0; i < n; ++i) //���������� ������� ����� ��������
        {
            for (int j = 0; j < m; ++j)
            {
                if (buf2[i][j] == 1) field[i][j] = buf2[i][j];
            }
        }
    }
    else return false;
    return true;
}


bool check(int** field, int** buf) // �������� �� ����
{
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (field[i][j] == 1 && buf[i][j] == 1)
            {
                return false;
            }
        }
    }
    return flag;
}


void checkLine(int** buf) //�������� ����� �� ��������
{
    bool flag;
    for (int i = n - 1; i >= 0; i--)
    {
        flag = true;
        for (int j = 0; j < m; j++)
        {
            if (buf[i][j] == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
        {
            for (int j = 0; j < m; j++)
            {
                buf[i][j] = 0;
            }
            for (int l = i; l >= 0; --l)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (buf[l][j] == 1)
                    {
                        buf[l][j] = 0;
                        buf[l + 1][j] = 1;
                    }
                }
            }
            points += 100;
            i = n;
        }
    }
}


void gameOver(int speed = 100)
{
    int key;
    system("cls");
    gotoxy(16, 10);
    cout << "GAME OVER";
    gotoxy(15, 11);
    cout << "Your Points: " << points;
    key = _getch();
    while (true)
    {
        if (key == 27) menu(speed, xb, yb);
    }
}


void start(int speed)
{
    points = 0;
    shaowBorderField(15, 1);
    int** field = new int* [n];//������������� ������� ������
    for (int i = 0; i < n; ++i)
    {
        field[i] = new int[m];
        for (int j = 0; j < m; ++j)
        {
            field[i][j] = 0;
        }
    }

    int** buf = new int* [n];//������������� ������� ����
    for (int i = 0; i < n; ++i)
    {
        buf[i] = new int[m];
        for (int j = 0; j < m; ++j)
        {
            buf[i][j] = 0;
        }
    }

    nextfigure = randomFigure();// ������������� ��������� ������
    createfigure();

    for (;;)
    {
        for (int i = 0; i < 4; ++i)//���������� ������ � ������ ������
        {
            for (int j = 0; j < 4; ++j)
            {
                field[i][j + m / 2] = figure[i][j];
            }
        }
        sp = speed;
        score(16, 1);
        bool canMove = true;
        for (; canMove;) //���� ������� ������
        {
            screen(field, buf);
            for (int j = 0; j < 5; j++)
            {
                moveKey(field, buf, sp);
                Sleep(sp);
            }
            canMove = move(field, buf);//���� �������� ����
        }
        for (int i = 0; i < n; ++i) //�������� �� ���� ����
        {
            for (int j = 0; j < m; ++j)
            {
                if (field[i][j] == 1 && i == 0)
                {
                    gameOver();
                }
            }

        }
        for (int i = 0; i < n; ++i) //���������� ������ ����� ������� � �������� ������
        {
            for (int j = 0; j < m; ++j)
            {
                if (field[i][j] == 1) buf[i][j] = field[i][j];
            }

        }
        clearField(field);
        checkLine(buf);
        createfigure();
    }
}