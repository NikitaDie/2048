#pragma once


int** creation();

int** makeClear(int** game_field);

int** move(int** game_field, int dir);

bool movesAvailable(int** game_field);

