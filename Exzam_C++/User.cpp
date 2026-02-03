#include "User.h"

User::User()
{
    
    cout << "Введите ID пользователя: "; cin >> id;
    
    do
    {
        int genderchoice;
        system("cls");
        cout << "Выберите пол:\n";
        cout << "1. M (Мужской)\n";
        cout << "2. F (Женский)\n";
        cout << "Ваш выбор (1-2): ";
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
        cout << "\nВведите Ваш возраст (1-100): ";
        cin >> age;
        if (age < 1 || age > 100)
        {
            cout << "Ошибка! Возраст должен быть от 1 до 100 лет\n";
        }
        else 
        { 
            system("cls");
            break;
           
        }
    } while (true);
    int citychoice;
    cout << "\nВыберите город:\n";
    cout << "1. Москва\n";
    cout << "2. Санкт-Петербург\n";
    cout << "3. Новосибирск\n";
    cout << "4. Екатеринбург\n";
    cout << "5. Другой\n";
    cout << "Ваш выбор (1-5): ";
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
        cout << "Введите Ваш город: ";
        getline(cin, city);
        cin.ignore();
        if (city.empty()) city = "Не указан";
        break;
    }
    }
    system("cls");
    int educhoice;
    cout << "\nВыберите образование:\n";
    cout << "1. Среднее\n";
    cout << "2. Среднее специальное\n";
    cout << "3. Высшее\n";
    cout << "4. Два высших\n";
    cout << "Ваш выбор (1-4): ";
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
   
    int interestcount;
    cout << "\nСколько интересов у вас есть? (0-10): ";
    cin >> interestcount;

    if (interestcount < 0) interestcount = 0;
    if (interestcount > 10) interestcount = 10;
    interests.clear();
    for (int i = 0; i < interestcount; i++)
    {
        string interest;
        cout << "Интерес #" << (i + 1) << " : ";    
        cin >> interest;
        if (interest.size() <= 10 && interest.size() >= 0)
        {
            interests.push_back(interest);
            cout << "Добавлен интерес: " << interests.back() << endl;
        }
    }

    cout << "\nПрофиль Создан с данными!\n";
    cout << "ID: " << id << " | Пол: " << gender << " | Возраст: " << age << endl;
    cout << "Город: " << city << " | Образование: " << education << endl;
    cout << "Интересов: " << interests.size() << endl;
    savetofile("users.txt");
    cout << "=====================================\n\n";
    system("pause");
    system("cls");
}
void User::savetofile(const string& filename)
{
    ofstream file(filename, ios::app);
    if (file.is_open()) 
    {
        file << id << " " << city << " " << gender << " " << education << " " << age << " " << interests.size() << endl;

        for (string& interest : interests)
        {
            file << interest << endl;
        }
        file.close();
        cout << "Пользователь " << id << " сохранён в " << filename << endl;     
    }
    else
    {

        cout << "Ошибка открытия файла!\n";
    }
}
