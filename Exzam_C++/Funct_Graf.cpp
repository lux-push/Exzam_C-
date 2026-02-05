#include "Funct_Graf.h"

void gotoxy(int X, int Y)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { X, Y };
    SetConsoleCursorPosition(hStdOut, coord);
}

int svaha_menu(const string& current_user)
{
    system("cls");
    gotoxy(30, 3); cout << "..:: СВАХА ::..";
    gotoxy(28, 4); cout << "Пользователь: " << current_user;
   
    gotoxy(25, 7);  cout << "1. Загрузить пользователей";
    gotoxy(25, 9);  cout << "2. Показать всех пользователей";
    gotoxy(25, 11); cout << "3. Найти матчи для себя";
    gotoxy(25, 13); cout << "4. ТОП-матчи для всех";
    gotoxy(25, 15); cout << "5. Мои лайки";
    gotoxy(25, 17); cout << "6. Лайкнуть пользователя";
    gotoxy(25, 19); cout << "7. Убрать лайк";
    gotoxy(25, 21); cout << "0. Выход";

    gotoxy(10, 24); cout << " стрелки | Enter | цифры 0-7 | Esc";

    int x = 22, y = 7, choice = 1;

    while (true)
    {
        gotoxy(x, y); cout << "> ";

        int first = _getch();
        gotoxy(x, y); cout << "  ";  

        if (first == 0 || first == 224)
        {
            int second = _getch();
            if (second == 80 && y < 21)  //вниз
            {
                y += 2;
                choice++;
            }
            if (second == 72 && y > 7)   //вверх
            {
                y -= 2;
                choice--;
            }
            continue;
        }
        else if (first == 13) //enter
        {
            return choice;
        }
        else if (first == 27) //esc
        {
            return 0;
        }
        else if (first >= 49 && first <= 55) //0-7
        {
            return first - 48;
        }
    }
}

