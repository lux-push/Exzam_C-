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
        cin.ignore();
        if (choice_user == 2)
        {
            User new_user(true);
            mm.adduser(new_user);                    
            mm.getusers().back().savetofile("users.txt");
            current_user = mm.getusers().back().getid();
            cout << "Профиль создан и сохранён!\n";

            cout << "\nТеперь создадим ваши предпочтения...\n";
            Preference new_pref;
            if (new_pref.getid() == current_user)
            {
                mm.addpref(new_pref);
                cout << "Предпочтения для " << current_user << " созданы!\n";
            }
        }
        else if (choice_user == 1)
        {
            string login_id, login_pass;
            cout << "ID: ";
            cin >> login_id;
            cout << "Пароль: ";
            cin >> login_pass;
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
                    cout << "\nСоздадим ваши предпочтения...\n";
                    Preference new_pref;
                    new_pref.setid(current_user);
                    mm.addpref(new_pref);
                    cout << "Предпочтения созданы!\n";
                }
            }
            else 
            {
                cout << "Ошибка! Пользователь не найден!\n";
                system("pause");
                return 1;
            }
        }
       

        int ret = 1, choice = 0;
        do
        {
            cin.clear();
            system("cls");
            show_menu(current_user);
            cin >> choice;
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
                break;
            }

            case 2:
            {
                print_banner("Все пользователи");
                mm.showfullusers();
                cout << endl << endl;
                break;
            }

            case 3:             
            {
                auto matches = mm.findmatchesbyid(current_user);
                show_matches(matches, current_user);
                cout << endl << endl;
                break;
            }

            case 4:             
            {
                print_banner("ТОП для всех");
                mm.showmatchs();
                cout << endl << endl;
                break;
            }
            case 5:  
            {
                mm.showmylikes(current_user);
                break;
            }

            case 6: 
            {
                print_banner("Поставить лайк");
                string target_id;
                cout << "ID для лайка: ";     
                cin.clear();
                cin >> target_id;
                mm.likeuser(current_user, target_id);
                break;
            }

            case 7:  
            {
                print_banner("Убрать лайк");
                cout << "ID для удаления лайка: ";
                string remove_id;
                cin >> remove_id;
                mm.unlikeuser(current_user, remove_id);
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

