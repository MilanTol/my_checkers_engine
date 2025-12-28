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
        return (square - getRow()) / 10;
    }

    int upRight()
    {
        return square - 9;
    }
    int upLeft()
    {
        return square - 11;
    }
    int downRight()
    {
        return square + 11;
    }
    int downLeft()
    {
        return square + 9;
    }

    int distanceFromSides()
    {    
        return std::max(getColumn(), 9 - getColumn());
    }
};
