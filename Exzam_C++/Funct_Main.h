#pragma once
#include "Header_Includs.h"
#include "User.h"
#include "Preference.h"
#include "Matchmaker.h"
void print_banner(const string& title);
void show_menu(string& current_user);
void show_matches(vector<pair<double, string>>& matches, string& for_user);
