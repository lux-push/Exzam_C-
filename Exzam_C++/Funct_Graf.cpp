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

bool register_vxod(Matchmaker& mm, string& current_user) 
{
    int choice_user;
    print_banner("Добро пожаловать в СВАХУ");

    cout << "====================== ВЫБОР ДЕЙСТВИЯ ======================\n";
    cout << "= 1. Войти в профиль                                       =\n";
    cout << "= 2. Регистрация нового профиля                            =\n";
    cout << "============================================================\n";
    cout << "= Выбор: ";
    cin >> choice_user;
    cin.ignore();
    if (choice_user == 2)
    {
        print_banner("Регистрация!");
        User new_user(true);
        mm.adduser(new_user);
        mm.getusers().back().savetofile("users.txt");
        current_user = mm.getusers().back().getid();
        print_banner("ПРОФИЛЬ СОЗДАН - " + current_user);
        cout << "= Профиль сохранён в users.txt\n";

        print_banner("Создание Препочтений!");
        cout << "= ======================================================\n";
        Preference new_pref;
        new_pref.setid(current_user);
        mm.addpref(new_pref);
        cout << "= Предпочтения для " << current_user << " созданы!\n";
        return true;
    }
    else if (choice_user == 1)
    {
        string login_id, login_pass;
        print_banner("Вход в Профиль!");
        cout << "====================\n";
        cout << "= ID: ";
        cin >> login_id;
        cout << "= Пароль: ";
        cin >> login_pass;
        print_banner("Загрузка Пользователей");
        mm.readtofile("users.txt");
        User* user = mm.login(login_id, login_pass);
        if (user)
        {
            current_user = login_id;
            cout << "Добро пожаловать, " << current_user << "!\n";
            bool has_prefs = false;
            for (auto& pref : mm.getpref())
            {
                if (pref.getid() == current_user)
                {
                    has_prefs = true;
                    break;
                }
            }
            if (!has_prefs)
            {
                print_banner("Добавление Предпочтений");
                cout << "= Создаём предпочтения для " << current_user << "...\n";
                Preference new_pref;
                new_pref.setid(current_user);
                mm.addpref(new_pref);
                cout << "Предпочтения созданы!\n";
            }
            return true;
        }
        else
        {
            print_banner("Ошибка Входа!");
            cout << "= Пользователь не найден!\n";
            cout << "= Проверьте ID и пароль\n";
            system("pause");
            return false;
        }
    }
    return false;

}