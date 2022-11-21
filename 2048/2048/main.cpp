﻿// 2048.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include "logic.h"
#include "game_input.h"
#include "game_graphic.h"
#include "common.h"


int main() {
	srand(time(NULL));

	setConsoleSize(WINDOW_W, WINDOW_H);

	int** game_field = creation();

	while (true)
	{
		showScreen(game_field);
		game_field = move(game_field, check_input());

	}

	return 0;
}
