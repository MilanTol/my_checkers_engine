#pragma once

#include "checker.hpp"
#include "turn.hpp"
#include "square.hpp"

struct Position
{   
    bool whiteSquares[100];
    bool blackSquares[100];
    bool emptySquares[100];
    Turn turn;
    
    Position(std::vector<Checker> checkers)
    {
        for (int i=0; i<100; i++)
        {
            whiteSquares[i] = false;
            blackSquares[i] = false;
        }

        for (Checker checker : checkers)
        {
            if (checker.isWhite())
                whiteSquares[checker.square] = true;
            if (checker.isBlack())
                blackSquares[checker.square] = true;
        }
    }
    
    void moveRight(int origin)
    {
        if (whiteSquares[origin])
        {
            whiteSquares[origin] = false;
            whiteSquares[Square(origin).upRight()] = true;
        }
        if (blackSquares[origin])
        {
            blackSquares[origin] = false;
            blackSquares[Square(origin).downRight()] = true;
        }
    }

    void moveLeft(int origin)
    {
        if (whiteSquares[origin])
        {
            whiteSquares[origin] = false;
            whiteSquares[Square(origin).upLeft()] = true;
        }
        if (blackSquares[origin])
        {
            blackSquares[origin] = false;
            blackSquares[Square(origin).downLeft()] = true;
        }
    }
 
    






    
};
