#pragma once
#include "Header_Includs.h"
#include "User.h"
#include "Preference.h"

class Matchmaker
{
private:
    vector<User> users;
    vector<Preference> preferences;

public:
    Matchmaker(bool auto_init = false);
    void create_pref();
    vector<User> getusers() { return users; }
    vector<Preference> getpref() { return preferences; }
    void adduser(User& user);
    void addpref(Preference& pref);

    User* login(string id, string pasw);           
    vector<pair<double, string>> findmatches(int ind);
    vector<pair<double, string>> findmatchesbyid(string user_id);
    vector<pair<double, string>> findmatchesforme(User* me);

    void showmatchs();
    double calculate(User& candidate, Preference& pref);
    void readtofile(const string& filename);
    void showfullusers();
    void showmylikes(string user_id);     
    void likeuser(string from_id, string to_id);
    void unlikeuser(string from_id, string to_id);

};
