#pragma once

#include "turn.hpp"
#include "square.hpp"

class Position
{   
protected:

    bool whiteCheckers[100];
    bool blackCheckers[100];
    bool whiteKings[100];
    bool blackKings[100];
            
public:

    Turn turn;

    Position()
    {   
        //init with false everywhere
        for (int i=0; i<100; i++)
        {
            whiteCheckers[i] = false;
            blackCheckers[i] = false;
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
            blackCheckers[square] = true;
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
            whiteCheckers[square] = true;
        }
    }

    Position(bool whiteSquares_init[100], bool blackSquares_init[100], Turn turn_init)
        : turn(turn_init)
    {
        for (int i = 0; i < 100; i++) {
            whiteCheckers[i] = whiteSquares_init[i];
            blackCheckers[i] = blackSquares_init[i];
        }
    }

    bool isWhite(Square square) const
    {
        return (whiteCheckers[square.square_id] or whiteKings[square.square_id]);
    }
    bool isBlack(Square square) const
    {
        return (blackCheckers[square.square_id] or blackKings[square.square_id]);
    }
    bool isWhiteChecker(Square square) const
    {
        return whiteCheckers[square.square_id];
    }
    bool isBlackChecker(Square square) const
    {
        return blackCheckers[square.square_id];
    }
    bool isWhiteKing(Square square) const
    {
        return whiteKings[square.square_id];
    }
    bool isBlackKing(Square square) const
    {
        return blackKings[square.square_id];
    }
    bool isEmpty(Square square) const
    {
        return (!this->isWhite(square) and !this->isBlack(square) and !this->isWhiteKing(square) and !this->isBlackKing(square));
    }

    void setWhiteChecker(Square square) 
    {
        whiteCheckers[square.square_id] = true;
    }
    void setBlackChecker(Square square)
    {
        blackCheckers[square.square_id] = true;
    }
    void setWhiteKing(Square square)
    {
        whiteKings[square.square_id] = true;
    }    
    void setBlackKing(Square square)
    {
        blackKings[square.square_id] = true;
    }    
    void setEmpty(Square square)
    {
        whiteCheckers[square.square_id] = false;
        blackCheckers[square.square_id] = false;
        whiteKings[square.square_id] = false;
        blackKings[square.square_id] = false;
    }

};
