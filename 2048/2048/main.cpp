// 2048.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include "logic.h"
#include "game_input.h"
#include "game_graphic.h"
#include "common.h"
#include "saving.h"


int main() {
	srand(time(NULL));

	setConsoleSize();

	bool is_end{ false };
	bool is_restart{ false };

	int** game_field = creation();
	int score{ 0 };
	int inp{ 0 };

	if(showMenu()) game_field = uploadSave(game_field, &score);

	while (true) {
	
		while (true)
		{
			showScreen(game_field, score);
			if (!movesAvailable(game_field)) break;

			inp = check_input();
			if (inp == 27) {
				is_end = true;
				break;
			}
			else if (inp == 114) {
				is_restart = true;
				break;
			}

			game_field = move(game_field, inp, &score);

		}

		if (is_end) break;
		else if (is_restart) {
			game_field = makeClear(game_field, &score);
			is_restart = false;
			continue;
		}

		if(!GameOverPrompt()) break;
		game_field = makeClear(game_field, &score);
	}

	return 0;
}
