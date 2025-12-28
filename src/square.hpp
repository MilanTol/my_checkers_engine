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
