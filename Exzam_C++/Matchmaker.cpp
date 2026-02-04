#include "Matchmaker.h"
vector<User> users = {};
Matchmaker::Matchmaker(bool auto_init )
{
    if(auto_init)
    {
        int usercount;
        cout << "Сколько пользователей создать? ";
        cin >> usercount;
        cout << "\n--- Создание " << usercount << " профилей ---\n";
        for (int i = 0; i < usercount; i++)
        {
            cout << "\nПользователь #" << (i + 1) << ":\n";
            User newuser;
            users.push_back(newuser);
        }

        int prefcount;
        cout << "\nСколько предпочтений создать? ";
        cin >> prefcount;

        cout << "\n--- Создание " << prefcount << " предпочтений ---\n";
        for (int i = 0; i < prefcount; i++)
        {
            cout << "\nПредпочтение #" << (i + 1) << ":\n";
            Preference newpref;
            preferences.push_back(newpref);
        }
        cout << "\nСваха Готова! " << users.size() << " пользователей, " << preferences.size() << " предпочтений\n\n";
        system("pause");
    }
}

vector<pair<double, User>> Matchmaker::findmatches(int ind)
{
    vector<pair<double, User>> matches;
    Preference& pref = preferences[ind];
    
    for (User& candidate : users) 
    {     
        if (candidate.getid() == pref.getid()) continue;
        double score = calculate(candidate, pref);
        if (score > 0)
        {
            matches.emplace_back(score, candidate);
        }
    }
    sort(matches.rbegin(), matches.rend());
    return matches;
}

void Matchmaker::showmatchs()
{
    for (int i = 0; i < preferences.size(); i++)
    {
        cout << "Для " << preferences[i].getid() << ":\n";
        auto matches = findmatches(i);
        for (int j = 0; j < min(3, (int)matches.size()); j++)
        {
            cout << "  " << (j + 1) << ". " << matches[j].second.getid() << " (score: " << fixed << setprecision(0) << matches[j].first << ")\n";
        }
        cout << "\n";
    }
}

double Matchmaker::calculate(User& candidate, Preference& pref)//подсчет баллов то есть по совпадением по которым мы потом вычислем лучших и худших
{
    double score = 0.0;

    if (pref.gethas_gen() && candidate.getgender() == pref.getgen())
    {
        score += 40;
    }
    if (candidate.getage() >= pref.getagemin() && candidate.getage() <= pref.getagemax())
    {
        score += 30;
    }
    if (pref.gethas_city() || candidate.getcity() == pref.getcity())
    {
        score += 20;
    }

    if (!pref.gethas_edu() && candidate.geteducation() == pref.getedu())
    {
        score += 15;
    }

    const auto& userinterests = candidate.getinterests();
    const auto& prefinterests = pref.getprefinterests();

    for (const string& pinterest : prefinterests)
    {
        for (const string& uinterest : userinterests) 
        {
            if (pinterest == uinterest) 
            {
                score += 10;
                break;  
            }
        }
    }

    return score;
}
void Matchmaker::readtofile(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Ошибка открытия файла: " << filename << endl;
    }
    string line;
    if (!getline(file, line))
    {
        cerr << "Пустой файл или ошибка чтения" << endl;
        file.close();
    }
    users.clear();  

    stringstream ss(line);
    int user_count;
    ss >> user_count;
    cout << "Загружаем " << user_count << " пользователей " << endl;

    for (int i = 0; i < user_count; ++i)
    {
        User u;
        u.getinterests().clear();
        for (int j = 0; j < user_count; ++j) 
        {
            if (!getline(file, line))
            {
                cout << "Ошибка чтения пользователя #" << (i + 1) << endl;
                break;
            }
            stringstream ss_line(line); // удобный разбор для чтения с файла чтоб просто разобрать строчки
            string id, city, gender, education, pasw;
            int age, interests_count;
            ss_line >> id >> city >> gender >> education >> age >> interests_count >> pasw;//разбираем строчку на отдельные данные по пробелам         
            u.setid(id);
            u.setcity(city);
            u.setgender(gender);
            u.seteducation(education);
            u.setage(age);
            u.setpassword(pasw);
            if (getline(file, line))
            {       
                if (!line.empty())
                {
                    u.getinterests().push_back(line);
                }
            }
        }
        
    }

    file.close();
    cout << "Загружено " << users.size() << "/" << user_count << " пользователей в вектор users" << endl;
}
void Matchmaker::showfullusers()
{
    for (size_t i = 0; i < users.size(); ++i)
    {
        User& u = users[i];     
        cout << "\n[" << (i + 1) << "] ID: " << u.getid() << " | Пол: " << u.getgender() << " | Возраст: " << u.getage() << endl;
        cout << "  Город: " << u.getcity() << " |  Образование: " << u.geteducation() << endl;     
        vector<string> interests = u.getinterests();
        cout << " Интересы (" << interests.size() << "): ";
        if (!interests.empty()) 
        {
            for (size_t j = 0; j < interests.size(); ++j)
            {
                cout << interests[j];
                if (j < interests.size() - 1) cout << ", ";
            }
        }
        else 
        {
            cout << "нет интересов";
        }
        cout << endl;
     
        cout << "===============================\n";
    }
    if (users.empty())
    {
        cout << "Пользователи не загружены! Вызовите readtofile()\n";
    }
}

User* Matchmaker::login(string id, string pass)
{
    readtofile("users.txt"); 
    for (User& u : users)
    {
        if (u.getid() == id && u.getpassword() == pass) 
        {
            return &u;
        }
    }
    return nullptr;
}

vector<pair<double, User>> Matchmaker::findmatchesforme(User* me)
{
    int pref_idx;
    for (int i = 0; i < preferences.size(); ++i)
    {
        if (preferences[i].getid() == me->getid()) 
        {
            pref_idx = i;
            break;
        }
    }
    return findmatches(pref_idx);
}