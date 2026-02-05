#pragma once
#include "Header_Includs.h"

class User
{
private:
    string id, city, gender, education, password;
    int age;
    vector<string> interests;
    vector<string> likes;
public:
    User(bool inter);
    string getid() { return id; }
    string getcity() { return city; }
    string getgender() { return gender; }
    string geteducation() { return education; }
    int getage() { return age; }
    vector<string>& getinterests() { return interests; }
    void setid(string i) { id = i; }
    void setcity(string c) { city = c; }
    void setgender(string g) { gender = g; }
    void seteducation(string e) { education = e; }
    void setage(int a) { age = a; }
    bool operator<(const User& other) const { return id < other.id || (id == other.id && password < other.password); }
    void savetofile(const string& filename);
    string getpassword() { return password; }
    void setpassword(string p) { password = p; }
    void save();
    vector<string>& getlikes() { return likes; }
    void addlike(string user_id);
    void removelike(string user_id);
    bool haslike(string user_id);
    void savelikestofile(const string& file);
    void loadlikes(ifstream& file, int count);
};
extern void print_banner(const string& title);
extern void show_menu(string& current_user);
extern void show_matches(vector<pair<double, string>>& matches, string& for_user);