#include "Header_Includs.h"
#include "User.h"
#include "Preference.h"
#include "Matchmaker.h"
#include "Funct_Graf.h"

int main()
{  
    
   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
        Matchmaker mm;
        string current_user = "";
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
            }
            else 
            {
                print_banner("Ошибка Входа!");
                cout << "= Пользователь не найден!\n";
                cout << "= Проверьте ID и пароль\n";
                system("pause");
                return 1;
            }
        }

        int choice = 0;
        do
        {
            system("cls");
            choice = svaha_menu(current_user);          
           /* cin.clear();
            
            show_menu(current_user); 
            cin >> choice;*/         
            if (choice < 0 || choice > 7) { cout << "Ошибка ввода!\n\n"; break; }
            switch (choice) 
            {
            case 1:
            {
                try
                {
                    print_banner("Загрузка");
                    auto size_before = mm.getusers().size();
                    mm.readtofile("users.txt");
                    cout << "Загружено: " << mm.getusers().size() << endl;
                }
                catch (...)
                {
                    cout << "Ошибка чтения файла!\n";
                }
                cout << endl << endl;
                system("pause");
                break;
            }

            case 2:
            {
                print_banner("Все пользователи");
                mm.showfullusers();
                cout << endl << endl;
                system("pause");
                break;
            }

            case 3:             
            {
                auto matches = mm.findmatchesbyid(current_user);
                show_matches(matches, current_user);
                cout << endl << endl;
                system("pause");
                break;
            }

            case 4:             
            {
                print_banner("ТОП для всех");
                mm.showmatchs();
                cout << endl << endl;
                system("pause");
                break;
            }
            case 5:  
            {
                mm.showmylikes(current_user);
                system("pause");
                break;
            }

            case 6: 
            {
                print_banner("Поставить лайк");
                string target_id;
                cout << "ID для лайка: ";                   
                cin >> target_id;
                mm.likeuser(current_user, target_id);
                system("pause");
                break;
            }

            case 7:  
            {
                print_banner("Убрать лайк");
                cout << "ID для удаления лайка: ";
                string remove_id;
                cin >> remove_id;
                mm.unlikeuser(current_user, remove_id);
                system("pause");
                break;
            }
            case 0:
            {
                print_banner("Досвидания!");
                break;
            }
            }

           /* if (choice != 0) 
            {
                int temp;
                print_banner("Повторить? 1-Да / 0-Нет: ");                            
                cin >> temp;
                ret = temp;  
                system("cls");
            }*/
        } while (choice != 0);
}

