#pragma once

#include "position.hpp"
#include "square.hpp"

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
        if (captureUpRight){return;}

        checkCaptureUpLeft(origin, position);
        if (captureUpLeft){return;}

        checkCaptureDownRight(origin, position);
        if (captureDownRight){return;}

        checkCaptureDownLeft(origin, position);
        if (captureDownLeft){return;}

        checkMoveLeft(origin, position);
        checkMoveRight(origin, position);
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
            position.emptySquares[Square(Square(origin).upLeft()).upLeft()] and
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
            position.emptySquares[Square(Square(origin).upLeft()).upLeft()] and
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
            position.emptySquares[Square(Square(origin).upRight()).upRight()] and
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
            position.emptySquares[Square(Square(origin).upRight()).upRight()] and
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
            position.emptySquares[Square(Square(origin).downRight()).downRight()] and
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
            position.emptySquares[Square(Square(origin).downRight()).downRight()] and
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
            position.emptySquares[Square(Square(origin).downLeft()).downLeft()] and
            (Square(origin).getRow() < 8) and
            (Square(origin).getColumn() > 1)
        )
        {captureDownLeft = true;}
            
        if 
        (
            position.turn.forBlack() and
            position.whiteSquares[Square(origin).downLeft()] and
            position.emptySquares[Square(Square(origin).downLeft()).downLeft()] and
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
            position.emptySquares[Square(origin).upRight()] and
            (Square(origin).getRow()>0) and
            (Square(origin).getColumn()<9)
        )
        {moveRight = true;}
        if
        (
            position.turn.forBlack() and
            position.emptySquares[Square(origin).downRight()] and
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
            position.emptySquares[Square(origin).upLeft()] and
            (Square(origin).getRow()>0) and
            (Square(origin).getColumn()>0)
        )
        {moveLeft = true;}
        if
        (
            position.turn.forBlack() and
            position.emptySquares[Square(origin).downLeft()] and
            (Square(origin).getRow()<9) and
            (Square(origin).getColumn()>0)
        )
        {moveLeft = true;}

    }

};
