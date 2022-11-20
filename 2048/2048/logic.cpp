#include <iostream>

struct Coordinates{
    int x{ 0 };
    int y{ 0 };
};

enum Direction {
    RIGHT, 
    LEFT,
    UP,
    DOWN,

};

void printField(int** game_field, const int SIZE) {
    for (int i{ 0 }; i < SIZE; i++) {
        for (int j{ 0 }; j < SIZE; j++) {
            std::cout << game_field[i][j] << " ";
        }
        std::cout << "\n";
    }
}

bool chekIfFull(int** game_field, const int SIZE, Coordinates cell) {
    if (game_field[cell.y][cell.x] > 0) {
        return true;
    }
    return false;
}

int generate_4_or_2() {                
    int arr[5] = {2, 2, 4, 2, 2 };
    return arr[rand() % 5];
}


Coordinates generateCoord() {
    Coordinates cell;
    cell.y = rand() % 4;
    cell.x = rand() % 4;

    return cell;
}
int** generateCell(int** game_field, const int SIZE) { //можно потом вынести 
    Coordinates cell = generateCoord();

    while(chekIfFull(game_field, SIZE, cell)) {
        cell = generateCoord();
    }
    game_field[cell.y][cell.x] = generate_4_or_2();

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

