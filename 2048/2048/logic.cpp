#include <iostream>
#include "common.h"
#include "generation.h"


int** creation() {
    int** game_field = new int* [SIZE];
    for (int i{ 0 }; i < SIZE; i++) {
        game_field[i] = new int[SIZE] {0};
    }

    game_field = generateCell(game_field); 
    game_field = generateCell(game_field);

    return game_field;
}

void printField(int** game_field) {
    for (int i{ 0 }; i < SIZE; i++) {
        for (int j{ 0 }; j < SIZE; j++) {
            std::cout << game_field[i][j] << " ";
        }
        std::cout << "\n";
    }
}


//int** up(int** game_field) {
//
//}

//void startOfGame() { //дописать
//
//}

//bool IsLose() {
//    retun true;
//}

//void endOfGame() {
//
//}

