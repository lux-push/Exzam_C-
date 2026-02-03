#pragma once
#include "Header_Includs.h"
class Preference
{
private: 
    string id;
    string pref_gender;      
    int pref_age_min;        
    int pref_age_max;     
    string pref_city;        
    string pref_education;   
    vector<string> pref_interests;
    //бул проверки нужны для того чтобы проверять заполнено ли поле
    bool has_gender;     
    bool has_age;
    bool has_city;
    bool has_education;
    bool has_interests;
public:
    Preference();
    string getid() { return id; }
    string getgen() { return pref_gender; }
    string getcity() { return pref_city; }
    vector<string> getprefinterests() { return pref_interests; }
    string getedu() { return pref_education; }
    int getagemin() { return pref_age_min; }
    int getagemax() { return pref_age_max; }
    bool gethas_gen() { return has_gender; }
    bool gethas_age() { return has_age; }
    bool gethas_city() { return has_city; }
    bool gethas_edu() { return has_education; }
    bool gethas_interests() { return has_interests; }

};

