#pragma once

#include "turn.hpp"
#include "square.hpp"

class Position
{   
protected:

    bool whiteSquares[100];
    bool blackSquares[100];
            
public:

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

    Position(bool whiteSquares_init[100], bool blackSquares_init[100], Turn turn_init)
        : turn(turn_init)
    {
        for (int i = 0; i < 100; i++) {
            whiteSquares[i] = whiteSquares_init[i];
            blackSquares[i] = blackSquares_init[i];
        }
    }

    bool isWhite(Square square) const
    {
        return (whiteSquares[square.square_id]);
    }
    bool isBlack(Square square) const
    {
        return (blackSquares[square.square_id]);
    }
    bool isEmpty(Square square) const
    {
        return (!this->isWhite(square) and !this->isBlack(square));
    }

    void setWhite(Square square) 
    {
        whiteSquares[square.square_id] = true;
    }
    void setBlack(Square square)
    {
        blackSquares[square.square_id] = true;
    }
    void setEmpty(Square square)
    {
        whiteSquares[square.square_id] = false;
        blackSquares[square.square_id] = false;
    }
    
};
