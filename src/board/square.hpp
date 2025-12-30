#pragma once

#include <algorithm>

struct Square
{
    int square_id;

    Square(int square_id_init) : 
        square_id(square_id_init)
    {}

    int getColumn() const
    {
        return square_id % 10;
    }
    int getRow() const
    {
        return (square_id - getColumn()) / 10;
    }

    Square upRight(int times=1) const
    {
        return Square(square_id - times*9);
    }
    Square upLeft(int times=1) const 
    {
        return Square(square_id - times*11);
    }
    Square downRight(int times=1) const
    {
        return Square(square_id + times*11);
    }
    Square downLeft(int times=1) const
    {
        return Square(square_id + times*9);
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
