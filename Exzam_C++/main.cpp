#include "Header_Includs.h"
#include "User.h"
#include "Preference.h"
#include "Matchmaker.h"



int main()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int ret = 1;
    Matchmaker mm;
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
            system("pause");
            system("cls");
            break;
        }
        case 4:
        {
            User new_user;
            cout << "Создание нового пользователя\n";
            users.push_back(new_user);
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

