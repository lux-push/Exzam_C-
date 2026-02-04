#pragma once
#include "Header_Includs.h"
#include "User.h"
#include "Preference.h"
extern vector<User> users;
class Matchmaker
{
private:
    vector<User> users;
    vector<Preference> preferences;
    
public:
    Matchmaker(bool auto_init = false);
    vector<User> getusers() { return users; }
    void adduser(User& user) { users.push_back(user); }
    void addpref(Preference& pref) { preferences.push_back(pref); }
    vector<pair<double, User>> findmatches(int ind);
    void showmatchs();
    double calculate(User& candidate,Preference& pref);
    void readtofile(const string& filename);
    void showfullusers();
    User* login(string id, string pasw);
    vector<pair<double, User>> findmatchesforme(User* me);
};
