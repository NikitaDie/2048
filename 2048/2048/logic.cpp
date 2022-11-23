#include <iostream>
#include "common.h"
#include "generation.h"


int** creation() {
    int** game_field = new int* [SIZE] {
    };

    for (int i{0}; i < SIZE; i++) {
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
    std::cout << "\n";
}


bool isCellsAvailable(int** game_field) {

    for (int i{ 0 }; i < SIZE; ++i) {
        for (int j{ 0 }; j < SIZE - 1; ++j) {
            if (game_field[i][j] == 0) return true;
        }
    }

    return false;
}

bool tileMatchesAvailableX(int** game_field) {

    for (int i{ 0 }; i < SIZE; ++i) {
        for (int j{ 0 }; j < SIZE - 1; ++j) {
            if (game_field[i][j] == game_field[i][j + 1] && game_field[i][j] != 0) return true;
        }
    }

    return false;
}

bool tileMatchesAvailableY(int** game_field) {

    for (int i{ 0 }; i < SIZE; ++i) {
        for (int j{ 0 }; j < SIZE - 1; ++j) {
            if (game_field[j][i] == game_field[j + 1][i] && game_field[j][i] != 0) return true;
        }
    }

    return false;
}

bool IsSchiftRight(int** game_field) {
 
    for (int i{ 0 }; i < SIZE; ++i) {
        bool cell{ false };
        for (int j{ 0 }; j < SIZE; ++j) {
            if (game_field[i][j] != 0 && !cell) cell = true;
            else if (game_field[i][j] == 0 && cell) return true;           
        }
    }

    return false;
}

bool IsSchiftLeft(int** game_field) {

    for (int i{ 0 }; i < SIZE; ++i) {
        bool cell{ false };
        for (int j{ SIZE - 1 }; j >= 0; --j) {
            if (game_field[i][j] != 0 && !cell) cell = true;
            else if (game_field[i][j] == 0 && cell) return true;
        }
    }

    return false;
}

bool IsSchiftDown(int** game_field) {

    for (int i{ 0 }; i < SIZE; ++i) {
        bool cell{ false };
        for (int j{ 0 }; j < SIZE; ++j) {
            if (game_field[j][i] != 0 && !cell) cell = true;
            else if (game_field[j][i] == 0 && cell) return true;
        }
    }

    return false;
}

bool IsSchiftUp(int** game_field) {

    for (int i{ 0 }; i < SIZE; ++i) {
        bool cell{ false };
        for (int j{ SIZE - 1 }; j >= 0; --j) {
            if (game_field[j][i] != 0 && !cell) cell = true;
            else if (game_field[j][i] == 0 && cell) return true;
        }
    }

    return false;
}


bool movesAvailable(int** game_field) {
    return  tileMatchesAvailableX(game_field) || isCellsAvailable(game_field);
}

void endOfGame() {
    std::cout << "MaslovaAIvedGovoril!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
}

bool IsLose(int** game_field) {
    if (!isCellsAvailable(game_field) && !tileMatchesAvailableX(game_field)) return true;
}


int* shiftRorL(int* game_field_stroka, int dir) {
    int x{ -1 };
    
    if (dir == LEFT) {
        for (int j{ 0 }; j < SIZE; j++) {

            if (game_field_stroka[j] == 0 && x < 0) {
                x = j;
            }

            else if (game_field_stroka[j] != 0 && x >= 0) {
                game_field_stroka[x] = game_field_stroka[j];
                game_field_stroka[j] = 0;
                j = x;
                x = -1;

            }

        }
    }
    else if (dir == RIGHT){
        for (int j{ SIZE - 1 }; j >= 0; j--) {

            if (game_field_stroka[j] == 0 && x < 0) {
                x = j;
            }
            else if (game_field_stroka[j] != 0 && x >= 0) {
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

int** move(int** game_field, int dir) {
    if (dir == LEFT or dir == RIGHT) { //3 if ???
        if (dir == LEFT) {
            if (!IsSchiftLeft(game_field) && !tileMatchesAvailableX(game_field)) return game_field;
        }
        else {
            if (!IsSchiftRight(game_field) && !tileMatchesAvailableX(game_field)) return game_field;
        }
        

        for (int i{ 0 }; i < SIZE; i++) {

            game_field[i] = shiftRorL(game_field[i], dir);
            game_field[i] = mergeRorL(game_field[i], dir);

        }
    }
    else {

        if (dir == UP) {
            if (!IsSchiftUp(game_field) && !tileMatchesAvailableY(game_field)) return game_field;
            dir = LEFT;
        }
        else {
            if (!IsSchiftDown(game_field) && !tileMatchesAvailableY(game_field)) return game_field;
            dir = RIGHT;
        }

        int* game_field_stolbik = new int [SIZE] {0};

        for (int j{ 0 }; j < SIZE; j++) {
            for (int i{ 0 }; i < SIZE; i++) {
                game_field_stolbik[i] = game_field[i][j];
            }
            game_field_stolbik = shiftRorL(game_field_stolbik, dir);
            game_field_stolbik = mergeRorL(game_field_stolbik, dir);
            for (int i{ 0 }; i < SIZE; i++) {
                game_field[i][j] = game_field_stolbik[i];
            }
        }

    }
    game_field = generateCell(game_field);
    return game_field;
}

//void startOfGame() { //дописать
//
//}



