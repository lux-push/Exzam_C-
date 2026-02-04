#pragma once
#include "Header_Includs.h"
class User
{
private:
	string id, city, gender, education, password;
	int age;
	vector<string> interests;

public:
    User();
    string getid() { return id; }
    string getcity() { return city; }
    string getgender() { return gender; }
    string geteducation() { return education; }
    int getage() { return age; }
    vector<string> getinterests() { return interests; }
    void setid(string i) { id = i; }
    void setcity(string c) { city = c; }
    void setgender(string g) { gender = g; }
    void seteducation(string e) { education = e; }
    void setage(int a) { age = a; }
    bool operator<(const User& other) const { return id < other.id || (id == other.id && password < other.password); }
    void savetofile(const string& filename);
    string getpassword() { return password; }
    void setpassword(string p) { password = p; }
};

