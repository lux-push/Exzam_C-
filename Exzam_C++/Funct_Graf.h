#pragma once
#include "Header_Includs.h"
#include "Matchmaker.h"


enum { LEFT = 75, DOWN = 80, UP = 72, RIGHT = 77, ENTER = 13, ESC = 27 };

void gotoxy(int X, int Y);
int svaha_menu(const string& current_user);
bool register_vxod(Matchmaker& mm, string& current_user);