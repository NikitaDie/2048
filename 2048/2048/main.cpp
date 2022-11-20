// 2048.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include "logic.h"
#include "game_input.h"

int main() {
	srand(time(NULL));

	int** game_field = creation();


	while (true)
	{
		printField(game_field);
		game_field = move(game_field, check_input());

	}
	
	return 0;
}
