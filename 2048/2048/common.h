#pragma once
#define SIZE 4

const int WINDOW_W = 84;
const int WINDOW_H = 49;

enum Directions { UP, DOWN, RIGHT, LEFT, NONE };

struct Coordinates {
    int x{ 0 };
    int y{ 0 };
};