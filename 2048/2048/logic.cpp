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
    game_field = generateCell(game_field);
    game_field = generateCell(game_field);
    game_field = generateCell(game_field);
    game_field = generateCell(game_field);
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


int** left(int** game_field) {
    for (int i{ 0 }; i < SIZE; i++) {
        int x { -1 };

        for (int j{ 0 }; j < SIZE; j++) {

            if (game_field[i][j] == 0 and x < 0) {
                x = j;
            } 
            else if(game_field[i][j] != 0 and x >= 0) {
                game_field[i][x] = game_field[i][j];
                game_field[i][j] = 0;
                j = x;
                x = -1;
   
            }

            /*if (game_field[i][j] == 0) {
                x = j;
            }
            else if (game_field[i][j] != 0 && game_field[i][j] == game_field[i][j + 1]) {
                x = NULL;
                game_field[i][j] *= 2;
                game_field[i][j] = 0;
            }
            else if (x) {

            }*/
        }

        for (int j{ 0 }; j < SIZE - 1; j++) {

            if (game_field[i][j] != 0 && game_field[i][j] == game_field[i][j + 1]) {
         
                game_field[i][j] *= 2;
                game_field[i][j + 1] = 0;
                //
                for (int k = j + 1; k < SIZE - 1; k++) {
                    game_field[i][k] = game_field[i][k + 1];
                }
                game_field[i][SIZE] = 0;
                //

            }

        }

    }
    return game_field;
}

//void startOfGame() { //дописать
//
//}

//bool IsLose() {
//    retun true;
//}

//void endOfGame() {
//
//}

