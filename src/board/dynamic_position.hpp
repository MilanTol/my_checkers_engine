#pragma once

#include "turn.hpp"
#include "square.hpp"
#include "position.hpp"
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

    void moveRight(Square origin)
    {
        if (this->isWhite(origin))
        {
            this->setEmpty(origin);
            this->setWhite(origin.upRight());
            turn.end();
        }
        if (this->isBlack(origin))
        {
            this->setEmpty(origin);
            this->setBlack(origin.downRight());
            turn.end();
        }
    }

    void moveLeft(Square origin)
    {   
        if (this->isWhite(origin))
        {   
            this->setEmpty(origin);
            this->setWhite(origin.upLeft());
            turn.end();
        }
        if (this->isBlack(origin))
        {
            this->setEmpty(origin);
            this->setBlack(origin.downLeft());
            turn.end();
        }
    }
 
    void move(Square origin, Square destination)
    {
        LegalMovesFromSquare legal_moves = LegalMovesFromSquare(origin, *this);
        
        if (legal_moves.moveLeft && origin.upLeft().square_id == destination.square_id)
        {
            moveLeft(origin);
        }
        if (legal_moves.moveLeft && origin.downLeft().square_id == destination.square_id)
        {
            moveLeft(origin);
        }
        if (legal_moves.moveRight && origin.upRight().square_id == destination.square_id)
        {
            moveRight(origin);
        }
        if (legal_moves.moveRight && origin.downRight().square_id == destination.square_id)
        {
            moveRight(origin);
        }  
    }
};