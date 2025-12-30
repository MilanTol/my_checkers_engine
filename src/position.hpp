#pragma once

#include "turn.hpp"

struct Position
{   
    bool whiteSquares[100];
    bool blackSquares[100];
    Turn turn;
    
    
    Position()
    {   
        //init with false everywhere
        for (int i=0; i<100; i++)
        {
            whiteSquares[i] = false;
            blackSquares[i] = false;
        }

        //init black checkers
        for (int i=0; i<20; i++)
        {   
            int square = 1 + 2*i;
            int column = square % 10;
            int row = (square - column) / 10;
            if (row%2)
            {
                square -= 1; 
            }
            blackSquares[square] = true;
        }

        //init white checkers
        for (int i=0; i<20; i++)
        {   
            int square = 99 - 2*i;
            int column = square % 10;
            int row = (square - column) / 10;
            if (row%2)
            {
                square -= 1;
            }
            whiteSquares[square] = true;
        }
    }

    Position(bool whiteSquares_input[100], bool blackSquares_input[100], Turn t)
        : turn(t)
    {
        for (int i = 0; i < 100; i++) {
            whiteSquares[i] = whiteSquares_input[i];
            blackSquares[i] = blackSquares_input[i];
        }
    }

    bool isEmpty(int square)
    {
        return (!whiteSquares[square] and !blackSquares[square]);
    }
    
};
