#pragma once

#include <algorithm>

struct Square
{
    int square;

    Square(int square_input) : 
        square(square_input)
    {}

    int getColumn()
    {
        return square % 10;
    }
    int getRow()
    {
        return (square - getColumn()) / 10;
    }

    int upRight(int times=1)
    {
        return square - times*9;
    }
    int upLeft(int times = 1)
    {
        return square - times*11;
    }
    int downRight(int times= 1)
    {
        return square + times*11;
    }
    int downLeft(int times= 1)
    {
        return square + times*9;
    }

    int distanceFromEdge()
    {    
        return std::min(
            {
            getColumn(), 
            9 - getColumn(),
            getRow(),
            9 - getRow()
            }
        );
    }
};
