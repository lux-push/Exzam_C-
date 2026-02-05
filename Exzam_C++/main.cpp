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
    register_vxod(mm, current_user);
    int choice = 0;
    do
    {
            system("cls");

            choice = svaha_menu(current_user);
            if (choice < -1 || choice > 7) { cout << "Ошибка ввода!\n\n"; break; }
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
    } while (choice != 0);
}

