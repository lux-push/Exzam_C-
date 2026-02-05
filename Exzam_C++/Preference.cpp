#include "Preference.h"

Preference::Preference()
{
    int genderchoice;
    print_banner("Создание предпочтений!");

    cout << "====================== ОСНОВНЫЕ ДАННЫЕ ======================\n";
    cout << "= ID пользователя: ";
    cin >> id;
   
    print_banner("Желаемый Пол");
    cout << "==================\n";
    cout << "= 1. M (Мужской)\n";
    cout << "= 2. F (Женский)\n";
    cout << "= 0. Не важно\n";
    cout << "= Выбор: ";
    cin >> genderchoice;

    if (genderchoice == 1)
    {
        pref_gender = "M";
        has_gender = true;
    }
    else if (genderchoice == 2)
    {
        pref_gender = "F";
        has_gender = true;
    }
    system("cls");
    int agechoice;
    print_banner("Возраст Партнера!");
    cout << "====================\n";
    cout << "= 1. 18-25\n";
    cout << "= 2. 25-35\n";
    cout << "= 3. 35-50\n";
    cout << "= 0. Не важно\n";
    cout << "= Выбор: ";
    cin >> agechoice;
    switch (agechoice)
    {
    case 1: pref_age_min = 18; pref_age_max = 25; has_age = true; break;
    case 2: pref_age_min = 25; pref_age_max = 35; has_age = true; break;
    case 3: pref_age_min = 35; pref_age_max = 50; has_age = true; break;
    case 0: has_age = false; break;
    }
    system("cls");
    int citychoice;
    print_banner("Желаемый Город Партнера!");
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
        pref_city = "Москва";
        break;
    }
    case 2:
    {
        pref_city = "Санкт-Петербург";
        break;
    }
    case 3:
    {
        pref_city = "Новосибирск";
        break;
    }
    case 4:
    {
        pref_city = "Екатеринбург";
        break;
    }
    case 5:
    {
        cout << "= Введите Ваш город: ";
        cin.ignore(1000, '\n');
        getline(cin, pref_city);
        has_city = true;
        if (pref_city.empty())
        {
            pref_city = "Не указан";
            has_city = false;
        }
        break;
    }


    system("cls");
    int educhoice;
    print_banner("Образование партнера!");
    cout << "======================\n";
    cout << "= 1. Среднее\n";
    cout << "= 2. Высшее\n";
    cout << "= 3. Любое\n";
    cout << "= Выбор: ";
    cin >> educhoice;
    switch (educhoice)
    {
    case 1: pref_education = "Среднее"; has_education = true; break;
    case 2: pref_education = "Высшее"; has_education = true; break;
    case 3: has_education = false; break;
    }
    system("cls");
    print_banner("Интересы Партнера!");
    cout << "====================\n";
    int interestCount;
    cout << "= Количество интересов (0=пропустить): ";
    cin >> interestCount;

    if (interestCount > 0)
    {
        pref_interests.clear();
        cout << "= Введите " << interestCount << " интерес(ов):\n";
        for (int i = 0; i < interestCount; i++)
        {
            cout << "= Интерес #" << (i + 1) << ": ";
            string interest;
            cin.ignore();
            getline(cin, interest);
            if (!interest.empty())
            {
                pref_interests.push_back(interest);
            }
        }
        has_interests = !pref_interests.empty();
    }
    else
    {
        has_interests = false;
    }
    system("cls");

    print_banner("Предпочтения Созданы!");
    cout << "====================== РЕЗУЛЬТАТ ======================\n";
    cout << "= ID: " << setw(25) << id << "=\n";
    if (has_gender) cout << "= Пол: " << setw(25) << pref_gender << "=\n";
    if (has_age) cout << "= Возраст: " << pref_age_min << "-" << pref_age_max << "     =\n";
    if (!pref_city.empty()) cout << "= Город: " << setw(25) << pref_city << "=\n";
    if (has_education) cout << "= Образование: " << setw(25) << pref_education << "=\n";
    if (has_interests) cout << "= Интересов: " << pref_interests.size() << "                 =\n";
    cout << "= ====================================================\n";
    system("pause");
    }
}




