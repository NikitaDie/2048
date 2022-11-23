#pragma once
#include <sstream> // может включить тогда заголовок в сpp

void setConsoleSize(short w, short h);

void showScreen(int** game_field);

bool GameOverPrompt();