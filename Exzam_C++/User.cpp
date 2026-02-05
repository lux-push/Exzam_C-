#include "User.h"
#include "Matchmaker.h"

User::User(bool inter)
{
    if(inter)
    {
        cout << "====================== Основнные Данные ======================\n";
        cout << "= ID пользователя: ";
        cin >> id;

        do
        {
            int genderchoice;
            system("cls");
            print_banner("Выбор Пола!");
            cout << "=======================\n";
            cout << "= 1. M (Мужской)\n";
            cout << "= 2. F (Женский)\n";
            cout << "= Выбор (1-2): ";
            cin >> genderchoice;
            if (genderchoice == 1)
            {
                gender = "M";
                break;
            }
            else if (genderchoice == 2)
            {
                gender = "F";
                break;
            }
            cout << "Ошибка! Поробуйте еще раз!\n\n";
        } while (true);
        do
        {
            system("cls");
            print_banner("Возраст!");
            cout << "==========\n";
            cout << "= Введите возраст (1-100): ";
            cin >> age;
            if (age < 1 || age > 100)
            {
                cout << "= Ошибка! Возраст должен быть от 1 до 100 лет\n";
                age = NULL;
            }
            else
            {
                system("cls");
                break;

            }
        } while (true);
        int citychoice;
        print_banner("Выбор Города!");
        cout << "==================\n";
        cout << "= 1. Москва\n";
        cout << "= 2. Санкт-Петербург\n";
        cout << "= 3. Новосибирск\n";
        cout << "= 4. Екатеринбург\n";
        cout << "= 5. Другой\n";
        cout << "= Выбор (1-5): ";
        cin >> citychoice;

        switch (citychoice)
        {
        case 1:
        {
            city = "Москва";
            break;
        }
        case 2:
        {
            city = "Санкт-Петербург";
            break;
        }
        case 3:
        {
            city = "Новосибирск";
            break;
        }
        case 4:
        {
            city = "Екатеринбург";
            break;
        }
        case 5:
        {
            cout << "= Введите город: ";
            cin.ignore(1000, '\n');
            getline(cin, city);
            if (city.empty()) city = "Не указан";
            break;
        }
        }
        system("cls");
        int educhoice;
        print_banner("Образование!");
        cout << "==============\n";
        cout << "= 1. Среднее\n";
        cout << "= 2. Среднее специальное\n";
        cout << "= 3. Высшее\n";
        cout << "= 4. Два высших\n";
        cout << "= Выбор (1-4): ";
        cin >> educhoice;

        switch (educhoice)
        {
        case 1:
        {
            education = "Среднее";
            break;
        }
        case 2:
        {
            education = "Среднее специальное";
            break;
        }
        case 3:
        {
            education = "Высшее";
            break;
        }
        case 4:
        {
            education = "Два высших";
            break;
        }

        }
        system("cls");

        print_banner("Интересы");
        cout << "==========\n";
        int interestcount;
        cout << "= Количество интересов (0-10): ";
        cin >> interestcount;

        if (interestcount < 0)
        {
            interestcount = 0;
        }
        if (interestcount > 10)
        {
            interestcount = 10;
        }
        interests.clear();
        for (int i = 0; i < interestcount; i++)
        {
            string interest;
            cout << "= Интерес #" << (i + 1) << ": ";
            cin >> interest;
            if (interest.size() > 10)
            {
                interest.resize(10);
            }
            interests.push_back(interest);
            cout << "= Добавлен: " << interests.back() << endl;
        }
        system("cls");
        print_banner("Пароль!");
        cout << "========\n";
        cout << "= Придумайте пароль (до 20 символов): ";
        cin >> password;
        if (password.size() > 20)
        {
            password.resize(20);
        }
        system("cls");
        print_banner("ПРОФИЛЬ СОЗДАН");
        cout << "====================== РЕЗУЛЬТАТ ======================\n";
        cout << "= ID:              " << setw(25) << id << "=\n";
        cout << "= Пол:             " << setw(25) << gender << "=\n";
        cout << "= Возраст:         " << setw(25) << age << "=\n";
        cout << "= Город:           " << setw(25) << city << "=\n";
        cout << "= Образование:     " << setw(25) << education << "=\n";
        cout << "= Интересов:       " << interests.size() << "\n";
        cout << "= ====================================================\n";
        system("pause");
        system("cls");
    }
    else
    {
        id = "empty";
    }
}
void User::savetofile(const string& filename)
{
    ofstream file(filename, ios::app);
    if (!file.is_open())
    {
        cout << "Ошибка открытия файла: " << filename << endl;
        return;
    }

    file << id << " " << city << " " << gender << " " << education << " " << age << " " << interests.size() << " " << password << endl;

    for (string& interest : interests) 
    {
        file << interest << endl;
    }

    file.close();
    cout << "Пользователь " << id << " сохранён в " << filename << endl;
}
void User::save()
{
    savetofile("users.txt");
}
void User::addlike(string user_id)
{
    if (!haslike(user_id))
    {
        likes.push_back(user_id);
        cout << "Добавлен лайк: " << user_id << endl;
    }
    else
    {
        cout << " Уже лайкали этого пользователя!\n";
    }
}
void User::removelike(string user_id)
{
    for (int i = 0; i < likes.size(); i++) 
    {
        if (likes[i] == user_id)
        {
            likes.erase(likes.begin() + i);
            cout << "Лайк удалён: " << user_id << endl;           
        }
    }
    cout << "Лайк не найден\n";
}
bool User::haslike(string user_id)
{
    for (string& liked : likes)
    {
        if (liked == user_id)
        {
            return true;
        }
    }
    return false;
}
void User::savelikestofile(const string& filen)
{
    ofstream file(filen, ios::app);
    if (!file.is_open()) return;

    file << id << " " << city << " " << gender << " " << education << " " << age << " " << interests.size() << " " << password << " " << likes.size() << endl;

    for (string& interest : interests)
    {
        file << interest << endl;
    }
    for (string& liked_id : likes) 
    {
        file << "LIKE:" << liked_id << endl;
    }

    file.close();
}
void User::loadlikes(ifstream& file, int count)
{
    likes.clear();

    for (int i = 0; i < count; i++)
    {
        string line;
        if (getline(file, line) && !line.empty())
        {          
            if (line.rfind("LIKE:", 0) == 0)//rfind = ищет где первое вхождение like возвращая позицию откуда читать
            {
                string liked_id = line.substr(5);// обрезаем лайк
                if (!liked_id.empty())
                {
                    likes.push_back(liked_id);
                }
            }
        }
    }
}





void print_banner(const string& title)
{
    system("cls");
    cout << "\n";
    cout << "====================== Сваха ===========================\n";
    cout << "= " << setw(30) << title << "                       =\n";
    cout << "========================================================\n\n";
}
void show_menu(string& current_user)
{
    print_banner("Главное меню - " + current_user);
    cout << "====================== Выберите Действие ======================\n";
    cout << "= 1.  Загрузить пользователей                                 =\n";
    cout << "= 2.  Показать всех пользователей                             =\n";
    cout << "= 3.  Найти матчи для себя                                    =\n";
    cout << "= 4.  ТОП-матчи для всех                                      =\n";
    cout << "= 5.  Мои лайки                                               =\n";
    cout << "= 6.  Лайкнуть пользователя                                   =\n";
    cout << "= 7.  Убрать лайк                                             =\n";
    cout << "= 0.  Выход                                                   =\n";
    cout << "===============================================================\n";
    cout << " Ваш выбор: ";
}
void show_matches(vector<pair<double, string>>& matches, string& for_user)
{
    print_banner(" ТОП-матчи для " + for_user);
    cout << "====================== РЕЙТИНГ СОВПАДЕНИЙ =====================\n";

    if (matches.empty())
    {
        cout << "= Нет подходящих кандидатов                              =\n";
        cout << "=  Загрузите пользователей и создайте предпочтения!       =\n";
    }
    else
    {
        for (int i = 0; i < matches.size() && i < 5; i++)
        {
            cout << "= " << (i + 1) << ".  " << matches[i].second;
            cout << " [" << matches[i].first << "%]  =\n";
        }
    }
    cout << "============================================================\n";
}