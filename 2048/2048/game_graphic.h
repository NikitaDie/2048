#pragma once
#include <sstream> // может включить тогда заголовок в сpp

void setConsoleSize();

void showScreen(int** game_field, int score);

bool GameOverPrompt();