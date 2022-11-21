#pragma once
#define SIZE 4

const int WINDOW_W = 85;
const int WINDOW_H = 50;

enum Directions { UP, DOWN, RIGHT, LEFT };

struct Coordinates {
    int x{ 0 };
    int y{ 0 };
};