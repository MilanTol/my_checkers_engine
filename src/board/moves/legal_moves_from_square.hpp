#pragma once

#include <vector>
#include <iostream>

#include "../square.hpp"
#include "../position.hpp"
#include "move.hpp"

struct LegalMovesFromSquare
{   
    Square square;
    std::vector<Move> moves;
    bool capturePossible = false;

    LegalMovesFromSquare(const Square& square_init, const Position& position):
        square(square_init)
    {           
        if (!squareHasTurn(position)){return;}

        checkCaptureUpRight(position);
        checkCaptureDownRight(position);
        checkCaptureDownLeft(position);
        checkCaptureUpLeft(position);
        
        if (capturePossible)
            return;
            
        checkMoveLeft(position);
        checkMoveRight(position);
    }

    bool squareHasTurn(const Position& position) const
    {
        if (position.turn.forWhite() and position.isWhite(square)) 
            return true;
        if (position.turn.forBlack() and position.isBlack(square))
            return true;
        
        return false;
    }
    
    void checkCaptureUpRight(const Position& position)
    {
        if 
        (               
            position.turn.forWhite() and
            position.isBlack(square.upRight()) and
            position.isEmpty(square.upRight(2)) and
            (square.getRow() > 1) and
            (square.getColumn() > 1)
        )
        {
            moves.push_back(Move(square, square.upRight(2), square.upRight()));
            std::cout << square.upRight().square_id << std::endl;
        }
        if 
        (
            position.turn.forBlack() and
            position.isWhite(square.upRight()) and
            position.isEmpty(square.upRight(2)) and
            (square.getRow() > 1) and
            (square.getColumn() < 8)        
        )
        {
            moves.push_back(Move(square, square.upRight(2), square.upRight()));
            capturePossible = true;
        }      
    }
    
    void checkCaptureDownRight(const Position& position)
    {
        if 
        (               
            position.turn.forWhite() and
            position.isBlack(square.downRight()) and
            position.isEmpty(square.downRight(2)) and
            (square.getRow() < 8) and
            (square.getColumn() < 8)
        )
        {
            moves.push_back(Move(square, square.downRight(2), square.downRight()));
            capturePossible = true;
        }
        if 
        (
            position.turn.forBlack() and
            position.isWhite(square.downRight()) and
            position.isEmpty(square.downRight(2)) and
            (square.getRow() < 8) and
            (square.getColumn() < 8)        
        )
        {
            moves.push_back(Move(square, square.downRight(2), square.downRight()));
            capturePossible = true;
        }           
    }

    void checkCaptureDownLeft(const Position& position)
    {
        if 
        (               
            position.turn.forWhite() and
            position.isBlack(square.downLeft()) and
            position.isEmpty(square.downLeft(2)) and
            (square.getRow() < 8) and
            (square.getColumn() > 1)
        )
        {
            moves.push_back(Move(square, square.downLeft(2), square.downLeft()));
            capturePossible = true;
        }
            
        if 
        (
            position.turn.forBlack() and
            position.isWhite(square.downLeft()) and
            position.isEmpty(square.downLeft(2)) and
            (square.getRow() < 8) and
            (square.getColumn() > 1)        
        )
        {
            moves.push_back(Move(square, square.downLeft(2), square.downLeft()));
            capturePossible = true;
        }                   
    }

    void checkCaptureUpLeft(const Position& position)
    {   
        if 
        (               
            position.turn.forWhite() and
            position.isBlack(square.upLeft()) and
            position.isEmpty(square.upLeft(2)) and
            (square.getRow() > 1) and
            (square.getColumn() > 1)
        )
        {
            moves.push_back(Move(square, square.upLeft(2), square.upLeft()));
            capturePossible = true;
        }
        if 
        (
            position.turn.forBlack() and
            position.isWhite(square.upLeft()) and
            position.isEmpty(square.upLeft(2)) and
            (square.getRow() > 1) and
            (square.getColumn() > 1)        
        )
        {
            moves.push_back(Move(square, square.upLeft(2), square.upLeft()));
            capturePossible = true;
        }       
    }

    void checkMoveRight(const Position& position)
    {
        if
        (
            position.turn.forWhite() and
            position.isEmpty(square.upRight()) and
            (square.getRow()>0) and
            (square.getColumn()<9)
        )
        {
            moves.push_back(Move(square, square.upRight()));
        }
        if
        (
            position.turn.forBlack() and
            position.isEmpty(square.downRight()) and
            (square.getRow()<9) and
            (square.getColumn()<9)
        )
        {
            moves.push_back(Move(square, square.downRight()));
        }

    }

    void checkMoveLeft(const Position& position)
    {
        if
        (
            position.turn.forWhite() and
            position.isEmpty(square.upLeft()) and
            (square.getRow()>0) and
            (square.getColumn()>0)
        )
        {
            moves.push_back(Move(square, square.upLeft()));
        }
        if
        (
            position.turn.forBlack() and
            position.isEmpty(square.downLeft()) and
            (square.getRow()<9) and
            (square.getColumn()>0)
        )
        {
            moves.push_back(Move(square, square.downLeft()));
        }

    }

};
