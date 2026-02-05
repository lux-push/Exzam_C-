#include "Matchmaker.h"
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

vector<pair<double, string>> Matchmaker::findmatches(int ind)
{
    vector<pair<double, string>> matches;
    Preference& pref = preferences[ind];
    
    for (User& candidate : users) 
    {     
        if (candidate.getid() == pref.getid()) 
        {
            continue;
        }
        double score = calculate(candidate, pref);
        if (score > 0)
        {
            matches.push_back(make_pair(score, candidate.getid()));
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
        for (int i = 0; i < preferences.size(); i++)
        {
            cout << "Для " << preferences[i].getid() << ":\n";
            auto matches = findmatches(i);
                if (matches.empty())
                {
                    cout << "  Нет подходящих кандидатов\n";
                }
                else 
                {
                    for (int j = 0; j < matches.size(); j++)
                    {                      
                        cout << "  " << (j + 1) << ". " << matches[j].second << " (score: " << matches[j].first << ")\n";
                    }
                }
            cout << "\n";
        }
    }
}
double Matchmaker::calculate(User& candidate, Preference& pref)//подсчет баллов то есть по совпадением по которым мы потом вычислем лучших и худших
{
    double score = 0.0;
    if (pref.gethas_gen() && candidate.getgender() == pref.getgen())
    {
        score += 40;
    }

    if (pref.gethas_age() && candidate.getage() >= pref.getagemin() && candidate.getage() <= pref.getagemax())
    {
        score += 30;
    }
    if (pref.gethas_city() && candidate.getcity() == pref.getcity())
    {
        score += 20;
    }
    if (pref.gethas_edu() && candidate.geteducation() == pref.getedu())
    {
        score += 15;
    }

    for (string& pinterest : pref.getprefinterests())
    {
        for (string& uinterest : candidate.getinterests())
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
    getline(file, line);

    while (getline(file, line)) 
    {
        if (line.empty())
        {
            continue;
        }

        stringstream ss(line);
        User u;
        string id, city, gender, education, password;
        int age, interest_count;

        if (!(ss >> id >> city >> gender >> education >> age >> interest_count >> password))
        {
            continue;
        }
        u.setid(id); u.setcity(city);
        u.setgender(gender);
        u.seteducation(education);
        u.setage(age);
        u.setpassword(password);
        u.getinterests().clear();

        for (int i = 0; i < interest_count; ++i)
        {
            if (getline(file, line) && !line.empty())
            {
                if (line.size() > 20)
                {
                    line.resize(20);
                }
                u.getinterests().push_back(line);
            }
        }
        users.push_back(u);
    }
    cout << "Загружено " << users.size() << " пользователей!" << endl;
        
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
    for (User& u : users)
    {
        if (u.getid() == id && u.getpassword() == pass) 
        {
            return &u;
        }
    }
    return nullptr;
}

vector<pair<double, string>> Matchmaker::findmatchesforme(User* me)
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
vector<pair<double, string>> Matchmaker::findmatchesbyid(string user_id)
{
    int pref_idx = -1;
    for (int i = 0; i < preferences.size(); i++)
    {
        if (preferences[i].getid() == user_id)
        {
            pref_idx = i;
            break;
        }
    }
    return findmatches(pref_idx);
}
