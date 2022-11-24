#pragma once


int** creation();

int** makeClear(int** game_field, int* score);

int** move(int** game_field, int dir, int* score);

bool movesAvailable(int** game_field);


