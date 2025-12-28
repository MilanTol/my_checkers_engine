#pragma once


#include <vector>
#include <iostream>

#include "square.hpp"
#include "position.hpp"

struct LegalMoves
{
    bool moveRight = false;
    bool moveLeft = false;
    bool captureUpRight = false;
    bool captureUpLeft = false;
    bool captureDownRight = false;
    bool captureDownLeft = false;

    LegalMoves(int origin, Position& position)
    {
        if (!checkTurn(origin, position)){return;}

        checkCaptureUpRight(origin, position);
        checkCaptureUpLeft(origin, position);
        checkCaptureDownRight(origin, position);
        checkCaptureDownLeft(origin, position);
        if (captureUpRight){return;}
        if (captureUpLeft){return;}
        if (captureDownRight){return;}
        if (captureDownLeft){return;}

        checkMoveLeft(origin, position);
        checkMoveRight(origin, position);
    }

    std::vector<int> legalSquares(int origin, Position& position)
    {
        std::vector<int> result;

        if (moveRight and position.turn.forWhite())
            result.push_back(Square(origin).upRight());
        if (moveRight and position.turn.forBlack())
            result.push_back(Square(origin).downRight());
        if (moveLeft and position.turn.forWhite())
            result.push_back(Square(origin).upLeft());
        if (moveLeft and position.turn.forBlack())
            result.push_back(Square(origin).downLeft());
        if (captureUpRight)
            result.push_back(Square(origin).upRight(2));
        if (captureDownLeft)
            result.push_back(Square(origin).downLeft(2));
        if (captureDownRight)
            result.push_back(Square(origin).downRight(2));
        if (captureUpLeft)
            result.push_back(Square(origin).upLeft(2));
        
        return result;
    }

    bool checkTurn(int origin, Position& position)
    {
        if (position.turn.forWhite() and position.whiteSquares[origin]) 
            return true;
        if (position.turn.forBlack() and position.blackSquares[origin])
            return true;
        
        return false;
    }

    void checkCaptureUpLeft(int origin, Position& position)
    {   
        if 
        (               
            position.turn.forWhite() and
            position.blackSquares[Square(origin).upLeft()] and
            position.isEmpty(Square(origin).upLeft(2)) and
            (Square(origin).getRow() > 1) and
            (Square(origin).getColumn() > 1)
        )
        {
            captureUpLeft = true;
        }
        if 
        (
            position.turn.forBlack() and
            position.whiteSquares[Square(origin).upLeft()] and
            position.isEmpty(Square(origin).upLeft(2)) and
            (Square(origin).getRow() > 1) and
            (Square(origin).getColumn() > 1)        
        )
        {
            captureUpLeft = true;
        }       
    }

    void checkCaptureUpRight(int origin, Position& position)
    {
        if 
        (               
            position.turn.forWhite() and
            position.blackSquares[Square(origin).upRight()] and
            position.isEmpty(Square(origin).upRight(2)) and
            (Square(origin).getRow() > 1) and
            (Square(origin).getColumn() > 1)
        )
        {
            captureUpRight = true;
        }
        if 
        (
            position.turn.forBlack() and
            position.whiteSquares[Square(origin).upRight()] and
            position.isEmpty(Square(origin).upRight(2)) and
            (Square(origin).getRow() > 1) and
            (Square(origin).getColumn() < 8)        
        )
        {
            captureUpRight = true;
        }      
    }

    void checkCaptureDownRight(int origin, Position& position)
    {
        if 
        (               
            position.turn.forWhite() and
            position.blackSquares[Square(origin).downRight()] and
            position.isEmpty(Square(origin).downRight(2)) and
            (Square(origin).getRow() < 8) and
            (Square(origin).getColumn() < 8)
        )
        {
            captureDownRight = true;
        }
        if 
        (
            position.turn.forBlack() and
            position.whiteSquares[Square(origin).downRight()] and
            position.isEmpty(Square(origin).downRight(2)) and
            (Square(origin).getRow() < 8) and
            (Square(origin).getColumn() < 8)        
        )
        {
            captureDownRight = true;
        }           
    }

    void checkCaptureDownLeft(int origin, Position& position)
{
    if 
    (               
        position.turn.forWhite() and
        position.blackSquares[Square(origin).downLeft()] and
        position.isEmpty(Square(origin).downLeft(2)) and
        (Square(origin).getRow() < 8) and
        (Square(origin).getColumn() > 1)
    )
    {captureDownLeft = true;}
        
    if 
    (
        position.turn.forBlack() and
        position.whiteSquares[Square(origin).downLeft()] and
        position.isEmpty(Square(origin).downLeft(2)) and
        (Square(origin).getRow() < 8) and
        (Square(origin).getColumn() > 1)        
    )
    {captureDownLeft = true;}                   
}

    void checkMoveRight(int origin, Position& position)
    {
        if
        (
            position.turn.forWhite() and
            position.isEmpty(Square(origin).upRight()) and
            (Square(origin).getRow()>0) and
            (Square(origin).getColumn()<9)
        )
        {moveRight = true;}
        if
        (
            position.turn.forBlack() and
            position.isEmpty(Square(origin).downRight()) and
            (Square(origin).getRow()<9) and
            (Square(origin).getColumn()<9)
        )
        {moveRight = true;}

    }

    void checkMoveLeft(int origin, Position& position)
    {
        if
        (
            position.turn.forWhite() and
            position.isEmpty(Square(origin).upLeft()) and
            (Square(origin).getRow()>0) and
            (Square(origin).getColumn()>0)
        )
        {moveLeft = true;}
        if
        (
            position.turn.forBlack() and
            position.isEmpty(Square(origin).downLeft()) and
            (Square(origin).getRow()<9) and
            (Square(origin).getColumn()>0)
        )
        {moveLeft = true;}

    }

};
