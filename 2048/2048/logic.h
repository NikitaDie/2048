#pragma once


int** creation();

void printField(int** game_field);

int** move(int** game_field, int dir);

//?
bool movesAvailable(int** game_field);

void endOfGame();