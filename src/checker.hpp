#pragma once

#include "config.hpp"

struct Checker
{
    int square;
    int color; //white is 1 , black is 0

    Checker(int sqr, int col):
        square(sqr),
        color(col)
        {}

    bool isWhite()
    {
        return (color == 1);
    }
    bool isBlack()
    {
        return (color == 0);
    }
};
