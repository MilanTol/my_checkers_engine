#pragma once

#include "checker.hpp"

struct Position
{   
    bool whiteSquares[100];
    bool blackSquares[100];
    
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
};
