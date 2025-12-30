#pragma once

#include "turn.hpp"
#include "square.hpp"
#include "position.hpp"

#include "moves/move.hpp"
#include "moves/legal_checker_moves.hpp"
#include "moves/legal_king_moves.hpp"

class DynamicPosition : public Position
{   

public:

    // constructor: copy arrays from Position
    DynamicPosition(const Position& input_position)
    {
        for (int i = 0; i < 100; i++) {
            whiteCheckers[i] = input_position.isWhiteChecker(Square(i));
            blackCheckers[i] = input_position.isBlackChecker(Square(i));
        }
    }
 
    void execute_move(Move move)
    {   
        if (this->turn.forWhite())
        {
            if (this->isWhite(move.origin))
            {
                this->setWhiteChecker(move.destination);
            }
            else if (this->isWhiteKing(move.origin))
            {
                this->setWhiteKing(move.destination);
            }

            this->setEmpty(move.origin);
            this->setEmpty(move.captured);

            if (move.destination.getRow() == 0)
            {
                this->setEmpty(move.destination);
                this->setWhiteKing(move.destination);
            }

            if (move.isCapture())
            {
                if (
                    LegalCheckerMoves(move.destination, *this).capturePossible or
                    LegalKingMoves(move.destination, *this).capturePossible
                    )
                {
                    return;
                }
            }
            std::cout<<"turn for black"<<std::endl;
            this->turn.end();
        }

        else if (this->turn.forBlack())
        {   
            if (this->isBlack(move.origin))
            {
                this->setBlackChecker(move.destination);
            }
            else if (this->isBlackKing(move.origin))
            {
                this->setBlackKing(move.destination);
            }

            this->setEmpty(move.origin);
            this->setEmpty(move.captured);

            if (move.destination.getRow() == 9)
            {
                this->setEmpty(move.destination);
                this->setBlackKing(move.destination);
            }

            if (move.isCapture())
            {
                if (
                    LegalCheckerMoves(move.destination, *this).capturePossible or
                    LegalKingMoves(move.destination, *this).capturePossible
                    )
                {
                    return;
                }
            }  
            std::cout<<"turn for white"<<std::endl;
            this->turn.end();
        }

    };
};