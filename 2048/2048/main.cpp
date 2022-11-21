﻿// 2048.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include "logic.h"
#include "game_input.h"
#include "game_graphic.h"

const int WINDOW_W = 85;
const int WINDOW_H = 50;

int main() {
	srand(time(NULL));

	setConsoleSize(WINDOW_W, WINDOW_H);

	int** game_field = creation();
	std::cout << AsciiArt2048();

	while (true)
	{
		printField(game_field);
		game_field = move(game_field, check_input());

	}
	
	return 0;
}
