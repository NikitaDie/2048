// 2048.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//



#include <iostream>
#include "logic.h"

int main() {
	srand(time(NULL));

	int** game_field = creation();
	while (true)
	{
		printField(game_field);
		std::cout << "\n";
	}

	return 0;
}
