#include <fstream>
#include "common.h"


bool checkSave() {
	return true;
}

void makeSave(int** game_field, int score) {
	std::ofstream save_file("save.txt");
	save_file << score << "\n";
	for (short i{ 0 }; i < SIZE; ++i) {
		for (short j{ 0 }; j < SIZE; ++j) {
			save_file << game_field[i][j] << " ";
		}
		save_file << "\n";
	}
	
	save_file.close();
}

int** uploadSave(int** game_field, int* score) {
	std::ifstream save_file("save.txt");

	save_file >> *score;

	for (short i{ 0 }; i < SIZE; ++i) {
		for (short j{ 0 }; j < SIZE; ++j) {
			save_file >> game_field[i][j];
		}
	}
	return game_field ;
}