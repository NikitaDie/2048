#pragma once
#define STYLE(x) "\033[" << static_cast<int>(x) << "m"

enum Colors {
    bold_on = 1,
    bold_off = 0,
    def = 39,
    black = 30,
    blue = 34,
    cyan = 36,
    dark_gray = 90,
    green = 32,
    light_blue = 94,
    light_cyan = 96,
    light_gray = 37,
    light_green = 92,
    light_magneta = 95,
    light_red= 91,
    light_yellow = 93,
    magneta = 35,
    red = 31,
    white = 97,
    yellow = 33,
};


const int numbers_color[11]{
    light_gray, light_red, light_cyan, light_blue, yellow, red, blue, cyan, light_magneta, yellow, green
};
