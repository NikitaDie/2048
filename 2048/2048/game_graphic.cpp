#include <iostream>
#include <sstream>
#include <conio.h>
#include <windows.h>
#include "common.h"
#include "styles.h"
#include "game_input.h"

// в заголовочный файл ???
const int WINDOW_W = 84;
const int WINDOW_H = 49;

const int TEXT_Y_SIZE = 14;

const float aspect = (float)WINDOW_W / WINDOW_H;
const float pixelAspect = 11.0f / 24.0f;

const int teil_lenght_y = 6; // the size of board bases on this value
const int teil_lenght_x = teil_lenght_y / pixelAspect;

const int lenght_y = SIZE * teil_lenght_y + 1;
const int lenght_x = SIZE * teil_lenght_x + 1;


const int beginning_y = TEXT_Y_SIZE;
const int beginning_x = (WINDOW_W - lenght_x) / 2;

//

void setConsoleSize() {
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD maxWindow = COORD{ WINDOW_W, WINDOW_H };
	SMALL_RECT srctWindow = { 0, 0, maxWindow.X - 1, maxWindow.Y - 1 };
	SMALL_RECT minWindow = { 0, 0, 0, 0 };
	SetConsoleWindowInfo(out_handle, true, &minWindow);
	SetConsoleScreenBufferSize(out_handle, maxWindow);
	SetConsoleWindowInfo(out_handle, true, &srctWindow);
}

int checkTheNumberOfDigits(int x) {
	int n{ 1 };
	while ((x /= 10) > 0) n++;
	return n;
}

void setColor(int x) {
	const char* n = "color 0"+(char)2;
	//n += (char)2;
	system(n);
}


void GotoXY(int X, int Y) {
	HANDLE  hConsole;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}

void AsciiArt2048() { // width 83 (2 space at the beginning), height 11
	std::string title_card_2048 = R"(
     /\\\\\\\\\          /\\\\\\\                /\\\         /\\\\\\\\\
    /\\\///////\\\      /\\\/////\\\            /\\\\\       /\\\///////\\\
    \///      \//\\\    /\\\    \//\\\         /\\\/\\\      \/\\\     \/\\\
               /\\\/    \/\\\     \/\\\       /\\\/\/\\\      \///\\\\\\\\\/
             /\\\//      \/\\\     \/\\\     /\\\/  \/\\\       /\\\///////\\\
           /\\\//         \/\\\     \/\\\   /\\\\\\\\\\\\\\\\   /\\\      \//\\\
          /\\\/            \//\\\    /\\\   \///////////\\\//   \//\\\      /\\\
          /\\\\\\\\\\\\\\\   \///\\\\\\\/              \/\\\      \///\\\\\\\\\/
          \///////////////      \///////                \///         \/////////
  )";

	std::ostringstream title_card_richtext;
	title_card_richtext << STYLE(green) << STYLE(bold_on) << title_card_2048 << STYLE(bold_off) << STYLE(def);
	std::cout << title_card_richtext.str();
}

void InputCommandList() {
	std::string sp = "  ";
	const auto input_commands_list_text = {
		"^ => Up", "< => Left", "v => Down",
		"> => Right", "R_CTRL => Save" };
	std::ostringstream str_os;
	for (const auto txt : input_commands_list_text) {
		str_os << STYLE(yellow) << sp << txt << STYLE(def) << "\n";
	}
	std::cout << str_os.str();
}

void printScore(int score) {

	GotoXY((WINDOW_W - beginning_x) - (checkTheNumberOfDigits(score) + 7), beginning_y + lenght_y + 1);

	std::string str_score = "SCORE: ";
	std::ostringstream score_text;		
	score_text << STYLE(yellow) << STYLE(bold_on) << str_score << score << STYLE(bold_off) << STYLE(def);
	 
	std::cout << score_text.str();

	GotoXY(0, beginning_y + lenght_y + 1);
}

bool GameOverPrompt() {
	std::string lose_game_text = "Game over! You lose.";
	std::string sp = "  ";
	std::ostringstream lose_richtext;
	lose_richtext << "\n" << STYLE(red) << STYLE(bold_on) << sp << lose_game_text << STYLE(def) << STYLE(bold_off) << "\n\n";
	std::cout << lose_richtext.str();
	std::cout << "Would you like to restart?  [y/n] ";
	return check_y();
}

void printBoard(int** game_field) {

	for (short y{0}; y < SIZE + 1; ++y) {
		GotoXY(beginning_x, (beginning_y + y * teil_lenght_y));
		for (int i{ 0 }; i < lenght_x / 2 + 1; ++i) { // dividieren cause * and space = 2 symbols
			std::cout << "* ";
		}

	}



	for (short x{0}; x < SIZE + 1; ++x) {
		for (int i{ 1 }; i < lenght_y; ++i) {
			if (i % teil_lenght_y == 0) {
				continue;
			}
			GotoXY(beginning_x + x * teil_lenght_x, beginning_y + i);
			std::cout << "*";
		}

	}

	int beginning_number_y = (teil_lenght_y - 2) / 2;
	int i_for_colors{ 0 };

	for (int i{ 0 }; i < SIZE; i++) {
		for (int j{ 0 }; j < SIZE; j++) {
			if (game_field[i][j] == 0) continue;

			int beginning_number_x = (teil_lenght_x - checkTheNumberOfDigits(game_field[i][j]) - 1) / 2;
			GotoXY(beginning_x + beginning_number_x + j * teil_lenght_x + 1, beginning_y + beginning_number_y + i * teil_lenght_y + 1);

			i_for_colors = numbers_color[(int)log2(game_field[i][j]) - 1];
			std::cout << STYLE(i_for_colors) << game_field[i][j] << STYLE(def);
		}
	}

	GotoXY(0, beginning_y + lenght_y + 1);
}

void showScreen(int** game_field, int score) {
	system("cls");
	AsciiArt2048();
	printBoard(game_field);
	printScore(score);
	InputCommandList();
}
