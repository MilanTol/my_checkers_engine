#pragma once

#include "turn.hpp"
#include "square.hpp"
#include "position.hpp"

#include "moves/move.hpp"
#include "moves/legal_moves.hpp"
#include "moves/legal_moves_from_square.hpp"

class DynamicPosition : public Position
{   

public:

    // constructor: copy arrays from Position
    DynamicPosition(const Position& input_position)
    {
        for (int i = 0; i < 100; i++) {
            whiteSquares[i] = input_position.isWhite(Square(i));
            blackSquares[i] = input_position.isBlack(Square(i));
        }
    }
 
    void execute_move(Move move)
    {   
        if (this->turn.forWhite())
        {
            this->setEmpty(move.origin);
            this->setWhite(move.destination);
            this->setEmpty(move.captured);

            if (move.destination.getRow() == 0)
            {
                this->setEmpty(move.destination);
                this->setWhiteKing(move.destination);
            }

            if (move.isCapture())
            {
                if (LegalMovesFromSquare(move.destination, *this).capturePossible)
                {
                    return;
                }
            }

            this->turn.end();
        }

        else if (this->turn.forBlack())
        {
            this->setEmpty(move.origin);
            this->setBlack(move.destination);
            this->setEmpty(move.captured);

            if (move.destination.getRow() == 9)
            {
                this->setEmpty(move.destination);
                this->setBlackKing(move.destination);
            }

            if (move.isCapture())
            {
                if (LegalMovesFromSquare(move.destination, *this).capturePossible)
                {
                    return;
                }
            }  

            this->turn.end();
        }

    };
};