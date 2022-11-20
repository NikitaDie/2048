// 2048.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "logic.h"

int main() {
	srand(time(NULL));

	const int SIZE = 4;
	int** game_field = new int* [SIZE];
	for (int i{ 0 }; i < SIZE; i++) {
		game_field[i] = new int[SIZE] {0};
	}

	game_field = generateCell(game_field, SIZE); //start
	game_field = generateCell(game_field, SIZE);

	while (true)
	{
		printField(game_field, SIZE);
		std::cout << "\n";
	}

	return 0;
}
