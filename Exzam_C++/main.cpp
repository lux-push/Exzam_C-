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
    User* current_user = nullptr;
    int choice_user;
    cout << "Добро пожаловать!\n";
    cout << "1. Войти в Профиль\n";
    cout << "2. Регистрация Профиля\n";
    cout << "3. Тестовая база (авто создание)\n";
    cin >> choice_user;

    if (choice_user == 2)
    {
        User new_user;
        mm.adduser(new_user);
        current_user = &mm.getusers().back();
        cout << "Профиль " << current_user->getid() << " создан!\\n";
    }
    else if (choice_user == 1)
    {     
        string login_id, login_pass;
        cout << "ID: ";
        cin >> login_id;
        cout << "Пароль: ";
        cin >> login_pass;
        mm.readtofile("users.txt");
        current_user = mm.login(login_id, login_pass);
        if (!current_user)
        {
            cout << "Неверный ID или пароль!\n";
            system("pause");
            return 1;
        }
    }
    else if (choice_user == 3)
    {
        Matchmaker mm_test(true);
        mm = mm_test;
    }
    else 
    {
        cout << "Неверный выбор!\\n";
        return 1;
    } 
    int ret = 1;
    int choice;
	do
	{ 
       
        cout << "\nДобро пожаловать в СВАХУ!\n";
        cout << "Выберите действие:\n";
        cout << "1. Загрузить пользователей из файла\n";
        cout << "2. Показать всех пользователей\n";
        cout << "3. Найти подходящих\n";
        cout << "4. Сохранить пользователя\n";
        cout << "5. Показать ТОП-матчи для всех\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор (0-4): ";
        cin >> choice;     
        switch (choice) 
        {
        case 1:
        {        
            mm.readtofile("users.txt");  
            system("pause");
            system("cls");
            break;
        }
      
        case 2:
            mm.showfullusers();
            system("pause");
            system("cls");
            break;
        case 3:
        {
            auto matches = mm.findmatchesforme(current_user);
            cout << "\n ТОП-3 мэтча для вас:\n";
            for (int i = 0; i < matches.size(); ++i)
            {
                cout << (i + 1) << ". " << matches[i].second.getid() << " (" << fixed << setprecision(0) << matches[i].first << ")\n";
            }
            system("pause");
            system("cls");
            break;
        }
        case 4:
        {
            User new_user;
            cout << "Создание нового пользователя\n";
            mm.adduser(new_user);
            system("pause");
            system("cls");
            break;
        }
        case 5:
        {
            mm.showmatchs();
            system("pause");
            system("cls");
            break;
        }
    
        case 0:
            cout << "До свидания!\n";
            ret = 2;
            system("pause");
            system("cls");
            break;
       
        }

        if (choice != 0)
        {
            cout << "\nХотите повторить? 1 - Да / 2 - Нет: ";
            cin >> ret;
            system("cls");
        }
    } while (ret == 1);

}

