#include "common.h"
#include <iostream>

bool chekIfFull(int** game_field, Coordinates cell) {
    if (game_field[cell.y][cell.x] > 0) {
        return true;
    }
    return false;
}

int generate_4_or_2() {
    int arr[5] = { 2, 2, 4, 2, 2 };
    return arr[rand() % 5];
}


Coordinates generateCoord() {
    Coordinates cell;
    cell.y = rand() % 4;
    cell.x = rand() % 4;

    return cell;
}
int** generateCell(int** game_field) { //можно потом вынести 
    Coordinates cell = generateCoord();

    while (chekIfFull(game_field, cell)) {
        cell = generateCoord();
    }
    game_field[cell.y][cell.x] = generate_4_or_2();

    return game_field;
}