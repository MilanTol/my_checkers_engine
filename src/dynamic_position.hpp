#pragma once

#include "checker.hpp"
#include "turn.hpp"
#include "square.hpp"
#include "legal_moves.hpp"

struct DynamicPosition
{   
    Position position;
    bool whiteSquares[100];
    bool blackSquares[100];
    Turn turn;
    
    // constructor: copy arrays from Position
    DynamicPosition(const Position& pos)
        : position(pos), turn(pos.turn)
    {
        for (int i = 0; i < 100; i++) {
            whiteSquares[i] = pos.whiteSquares[i];
            blackSquares[i] = pos.blackSquares[i];
        }
    }

    void updatePosition()
    {
        position = Position(whiteSquares, blackSquares, turn);
    }

    void moveRight(int origin)
    {
        if (whiteSquares[origin])
        {
            whiteSquares[origin] = false;
            whiteSquares[Square(origin).upRight()] = true;
            turn.end();
        }
        if (blackSquares[origin])
        {
            blackSquares[origin] = false;
            blackSquares[Square(origin).downRight()] = true;
            turn.end();
        }
    }

    void moveLeft(int origin)
    {   
        if (whiteSquares[origin])
        {   
            whiteSquares[origin] = false;
            whiteSquares[Square(origin).upLeft()] = true;
            turn.end();
        }
        if (blackSquares[origin])
        {
            blackSquares[origin] = false;
            blackSquares[Square(origin).downLeft()] = true;
            turn.end();
        }
    }
 
    void move(int origin, int destination)
    {
        LegalMoves legal_moves = LegalMoves(origin, position);
        
        if (legal_moves.moveLeft && Square(origin).upLeft() == destination)
        {
            moveLeft(origin);
        }
        if (legal_moves.moveLeft && Square(origin).downLeft() == destination)
        {
            moveLeft(origin);
        }
        if (legal_moves.moveRight && Square(origin).upRight() == destination)
        {
            moveRight(origin);
        }
        if (legal_moves.moveRight && Square(origin).downRight() == destination)
        {
            moveRight(origin);
        }  

        updatePosition();
    }
};