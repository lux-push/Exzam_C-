#include "Preference.h"

Preference::Preference()
{
    
    cout << "Введите ID пользователя: "; cin >> id;
    int genderchoice;
    cout << "\nЖелаемый пол партнера (0=пропустить):\n";
    cout << "1. M (Мужской)\n";
    cout << "2. F (Женский)\n";
    cout << "0. Не важно\n";
    cout << "Ваш выбор: ";
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
    system("pause");
    system("cls");
    int agechoice;
    cout << "\nВозраст партнера:\n";
    cout << "1. 18-25\n";
    cout << "2. 25-35\n";
    cout << "3. 35-50\n";
    cout << "0. Не важно\n";
    cout << "Ваш выбор: ";
    cin >> agechoice;
    switch (agechoice)
    {
    case 1: pref_age_min = 18; pref_age_max = 25; has_age = true; break;
    case 2: pref_age_min = 25; pref_age_max = 35; has_age = true; break;
    case 3: pref_age_min = 35; pref_age_max = 50; has_age = true; break;
    case 0: has_age = false; break;
    }
    system("pause");
    system("cls");
    int citychoice;
    cout << "\nЖелаемый город партнера:\n";
    cout << "1. Москва\n";
    cout << "2. Санкт-Петербург\n";
    cout << "3. Любой\n";
    cout << "Ваш выбор: ";
    cin >> citychoice;
    switch (citychoice)
    {
    case 1: pref_city = "Москва"; has_city = true; break;
    case 2: pref_city = "Санкт-Петербург"; has_city = true; break;
    case 3: break;
    }
    system("pause");
    system("cls");
    int educhoice;
    cout << "\nЖелаемое образование партнера:\n";
    cout << "1. Среднее\n";
    cout << "2. Высшее\n";
    cout << "3. Любое\n";
    cout << "Ваш выбор: ";
    cin >> educhoice;
    switch (educhoice)
    {
    case 1: pref_education = "Среднее"; has_education = true; break;
    case 2: pref_education = "Высшее"; has_education = true; break;
    case 3: has_education = false; break;
    }
    system("pause");
    system("cls");
    int interestCount;
    cout << "\nСколько интересов должно быть у партнера? (0=пропустить): ";
    cin >> interestCount;

    if (interestCount > 0)
    {
        pref_interests.clear();
        cout << "Введите " << interestCount << " интерес(ов):\n";
        for (int i = 0; i < interestCount; i++) {
            cout << "Интерес #" << (i + 1) << ": ";
            string interest;
            cin.ignore();
            getline(cin, interest);
            if (!interest.empty()) {
                pref_interests.push_back(interest);
            }
        }
        has_interests = !pref_interests.empty();
    }
    else
    {
        has_interests = false;
    }
    system("pause");
    system("cls");

    cout << "\n Мы учли ваши предпочтения!\n";
    cout << "ID: " << id << endl;
    if (has_gender == true) cout << "Пол: " << pref_gender << endl;
    if (has_age == true) cout << "Возраст: " << pref_age_min << "-" << pref_age_max << endl;
    if (has_city == true) cout << "Город: " << pref_city << endl;
    if (has_education == true) cout << "Образование: " << pref_education << endl;
    if (has_interests == true) cout << "Интересов: " << pref_interests.size() << endl;
    cout << "=============================\n\n";
}




