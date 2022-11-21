#include <iostream>
#include <sstream>
#include <conio.h>
#include <windows.h>
#include "common.h"


void setConsoleSize(short w, short h) {
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD maxWindow = COORD{ w, h };
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


void GotoXY(int X, int Y) {
	HANDLE  hConsole;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}

/*std::string AsciiArt2048() { // width 83 (2 space at the beginning), height 11
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
	//title_card_richtext << green << bold_on << title_card_2048 << bold_off << def;
	title_card_richtext << title_card_2048;
	//title_card_richtext << "\n\n\n";
	return title_card_richtext.str();
}*/

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
	//title_card_richtext << green << bold_on << title_card_2048 << bold_off << def;
	title_card_richtext << title_card_2048;

	std::cout << title_card_richtext.str();
}

void InputCommandList() {
	constexpr auto sp = "  ";
	const auto input_commands_list_text = {
		"W or K or ↑ => Up", "A or H or ← => Left", "S or J or ↓ => Down",
		"D or L or → => Right", "Z or P => Save" };
	std::ostringstream str_os;
	for (const auto txt : input_commands_list_text) {
		str_os << sp << txt << "\n";
	}
	std::cout << str_os.str();
}

void printBoard(int** game_field) {
	float aspect = (float)WINDOW_W / WINDOW_H;
	float pixelAspect = 11.0f / 24.0f;

	const int teil_lenght_y = 6; // the size of board bases on this value
	int teil_lenght_x = teil_lenght_y / pixelAspect;

	int lenght_y = SIZE * teil_lenght_y + 1;
	int lenght_x = SIZE * teil_lenght_x + 1;


	int beginning_y = 15; // the name of the game takes 15 symbols height
	int beginning_x = (WINDOW_W - lenght_x) / 2;


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

	for (int i{ 0 }; i < SIZE; i++) {
		for (int j{ 0 }; j < SIZE; j++) {
			int beginning_number_x = (teil_lenght_x - checkTheNumberOfDigits(game_field[i][j]) - 1) / 2;
			GotoXY(beginning_x + beginning_number_x + j * teil_lenght_x + 1, beginning_y + beginning_number_y + i * teil_lenght_y + 1);
			std::cout << game_field[i][j];
		}
	}

	GotoXY(0, beginning_y + lenght_y + 1);
}

void showScreen(int** game_field) {
	system("cls");
	AsciiArt2048();
	printBoard(game_field);
	InputCommandList();
}
