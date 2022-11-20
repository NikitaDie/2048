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

int* shiftRorL(int* game_field_stroka, int dir) {
    int x{ -1 };
    
    if (dir == LEFT) {
        for (int j{ 0 }; j < SIZE; j++) {

            if (game_field_stroka[j] == 0 and x < 0) {
                x = j;
            }
            else if (game_field_stroka[j] != 0 and x >= 0) {
                game_field_stroka[x] = game_field_stroka[j];
                game_field_stroka[j] = 0;
                j = x;
                x = -1;

            }

        }
    }
    else if (dir == RIGHT){
        for (int j{ SIZE - 1 }; j >= 0; j--) {

            if (game_field_stroka[j] == 0 and x < 0) {
                x = j;
            }
            else if (game_field_stroka[j] != 0 and x >= 0) {
                game_field_stroka[x] = game_field_stroka[j];
                game_field_stroka[j] = 0;
                j = x;
                x = -1;

            }

        }
    }

    return game_field_stroka;
}

int* mergeRorL(int* game_field_stroka, int dir) {

    if (dir == LEFT) {
        for (int j{ 0 }; j < SIZE - 1; j++) {

            if (game_field_stroka[j] != 0 && game_field_stroka[j] == game_field_stroka[j + 1]) {

                game_field_stroka[j] *= 2;
                game_field_stroka[j + 1] = 0;
                // может создать функцию
                for (int k = j + 1; k < SIZE - 1; k++) {
                    game_field_stroka[k] = game_field_stroka[k + 1];
                }
                game_field_stroka[SIZE] = 0;
                //
            }
        }
    }
    else if (dir == RIGHT) {
        for (int j{ SIZE - 1 }; j > 0; j--) {

            if (game_field_stroka[j] != 0 && game_field_stroka[j] == game_field_stroka[j - 1]) {

                game_field_stroka[j] *= 2;
                game_field_stroka[j - 1] = 0;
                // может создать функцию
                for (int k = j - 1; k > 0; k--) {
                    game_field_stroka[k] = game_field_stroka[k - 1];
                }
                game_field_stroka[SIZE] = 0;
                //
            }
        }
    }
    

    return game_field_stroka;
}

int** leftORrihgt(int** game_field) {
    for (int i{ 0 }; i < SIZE; i++) {

        game_field[i] = shiftRorL(game_field[i], RIGHT);
        game_field[i] = mergeRorL(game_field[i], RIGHT);

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

