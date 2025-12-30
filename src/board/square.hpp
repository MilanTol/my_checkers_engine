#pragma once

#include <algorithm>

struct Square
{
    int square;

    Square(int square_init) : 
        square(square_init)
    {}

    int getColumn() const
    {
        return square % 10;
    }
    int getRow() const
    {
        return (square - getColumn()) / 10;
    }

    int upRight(int times=1) const
    {
        return square - times*9;
    }
    int upLeft(int times=1) const 
    {
        return square - times*11;
    }
    int downRight(int times=1) const
    {
        return square + times*11;
    }
    int downLeft(int times=1) const
    {
        return square + times*9;
    }

    int distanceFromEdge() const
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
