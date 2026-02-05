#include "Header_Includs.h"
#include "User.h"
#include "Preference.h"
#include "Matchmaker.h"


int main()
{  
    
   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
        Matchmaker mm;
        string current_user = "";
        int choice_user;
        cout << "Добро Пожаловать!\n";
        cout << "1. Войти в Профиль\n";
        cout << "2. Регистрация Профиля\n";
        cin >> choice_user;        
        if (choice_user == 2)
        {
            User new_user;
            mm.adduser(new_user);                    
            mm.getusers().back().savetofile("users.txt"); 
            cout << "Профиль создан и сохранён!\n";
        }
        else if (choice_user == 1) 
        {
            string login_id, login_pass;
            cout << "ID: "; cin >> login_id;
            cout << "Пароль: "; cin >> login_pass;
            mm.readtofile("users.txt");
            User* user = mm.login(login_id, login_pass);
            if (!user)
            {
                cout << "Неверный ID или пароль!\n";
                system("pause");
                return 1;
            }
            cout << "Добро пожаловать, " << current_user << "!\n";
        }

        int ret = 1, choice = 0;
        do {
            cout << "\nДобро пожаловать в СВАХУ!\n";
            cout << "1. Загрузить пользователей\n";
            cout << "2. Показать всех пользователей\n";
            cout << "3. Найти подходящих (нужны предпочтения)\n";
            cout << "4. Создать нового пользователя\n";
            cout << "5. ТОП-матчи для всех (нужны предпочтения)\n";
            cout << "0. Выход\n";
            cout << "Выбор: ";
            cin >> choice;

            switch (choice) {
            case 1:
            {
                mm.readtofile("users.txt");
                cout << "Загружено " << mm.getusers().size() << " пользователей\n";
                cin.clear();
                cin.ignore(10000, '\n');

                system("pause"); 
                system("cls");
                break;
            }

            case 2:
            {
                mm.showfullusers();
                system("pause"); system("cls");
                break;
            }

            case 3:             
            {
                auto matches = mm.findmatchesbyid(current_user);
                cout << "\n ТОП-3 мэтча для вас:\n";
                for (int i = 0; i < matches.size(); ++i)
                {                 
                    cout << (i + 1) << ". " << matches[i].second << " (" << matches[i].first << ")\n";
                }
                system("pause");
                system("cls");
                break;
            }

            case 4:
            {
              
            }
            system("pause"); system("cls");
            break;

            case 5:             
            {
                mm.showmatchs();
                system("pause"); system("cls");
                break;
            }

            case 0:
            {
                cout << "До свидания!\n";
                ret = 0;
                break;
            }
            }

            if (choice != 0) 
            {
                int again;
                cout << "Повторить? 1-Да / 0-Нет: ";
                cin >> again;
                ret = again;
                system("cls");
            }
        } while (ret == 1);
}

