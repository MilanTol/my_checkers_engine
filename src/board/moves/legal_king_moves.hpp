#pragma once

#include <vector>
#include <iostream>

#include "../square.hpp"
#include "../position.hpp"
#include "move.hpp"

struct LegalKingMoves
{   
    Square square;
    std::vector<Move> moves;
    bool capturePossible = false;

    LegalKingMoves(const Square& square_init, const Position& position):
        square(square_init)
    {           
        if (!squareHasTurn(position)){return;}
        
        checkCaptureUpRight(position);
        checkCaptureDownRight(position);
        checkCaptureDownLeft(position);
        checkCaptureUpLeft(position);
                
        if (capturePossible)
            return;
            
        checkMoveUpRight(position);
        checkMoveDownRight(position);
        checkMoveDownLeft(position);
        checkMoveUpLeft(position);
    }

    bool squareHasTurn(const Position& position) const
    {
        if (position.turn.forWhite() and position.isWhiteKing(square)) 
            return true;
        if (position.turn.forBlack() and position.isBlackKing(square))
            return true;
        
        return false;
    }
    
    void checkCaptureUpRight(const Position& position)
    {
        for (int i=1; square.upRight(i).distanceFromEdge() > 0; i++)
            if 
            (               
                position.turn.forWhite() and
                position.isBlack(square.upRight(i)) and
                position.isEmpty(square.upRight(i + 1))
            )
            {
                moves.push_back(Move(square, square.upRight(i+1), square.upRight(i)));
                capturePossible = true;
                break;
            }
            else if 
            (
                position.isBlack(square.upRight(i)) and
                position.isBlack(square.upRight(i+1))
            )
            {
                break;
            }
            
        for (int i=1; square.upRight(i).distanceFromEdge()>0; i++)
            if 
            (
                position.turn.forBlack() and
                position.isWhite(square.upRight(i)) and
                position.isEmpty(square.upRight(i+1)) and
                (square.getRow() > 1) and
                (square.getColumn() < 8)        
            )
            {
                moves.push_back(Move(square, square.upRight(i+1), square.upRight(i)));
                capturePossible = true;
                break;
            }     
            else if 
            (
                position.isWhite(square.upRight(i)) and
                position.isWhite(square.upRight(i+1))
            )
            {
                break;
            } 
    }
    
    void checkCaptureDownRight(const Position& position)
    {
        for (int i = 1; square.downRight(i).distanceFromEdge() > 0; i++)
            if
            (
                position.turn.forWhite() and
                position.isBlack(square.downRight(i)) and
                position.isEmpty(square.downRight(i + 1))
            )
            {
                moves.push_back(Move(square, square.downRight(i + 1), square.downRight(i)));
                capturePossible = true;
                break;
            }
            else if 
            (
                position.isBlack(square.downRight(i)) and
                position.isBlack(square.downRight(i+1))
            )
            {
                break;
            } 

        for (int i = 1; square.downRight(i).distanceFromEdge() > 0; i++)
            if
            (
                position.turn.forBlack() and
                position.isWhite(square.downRight(i)) and
                position.isEmpty(square.downRight(i + 1))
            )
            {
                moves.push_back(Move(square, square.downRight(i + 1), square.downRight(i)));
                capturePossible = true;
                break;
            }
            else if 
            (
                position.isWhite(square.downRight(i)) and
                position.isWhite(square.downRight(i+1))
            )
            {
                break;
            } 
    }

    void checkCaptureDownLeft(const Position& position)
    {
        for (int i = 1; square.downLeft(i).distanceFromEdge() > 0; i++)
            if
            (
                position.turn.forWhite() and
                position.isBlack(square.downLeft(i)) and
                position.isEmpty(square.downLeft(i + 1))
            )
            {
                moves.push_back(Move(square, square.downLeft(i + 1), square.downLeft(i)));
                capturePossible = true;
                break;
            }
            else if 
            (
                position.isBlack(square.downLeft(i)) and
                position.isBlack(square.downLeft(i+1))
            )
            {
                break;
            } 

        for (int i = 1; square.downLeft(i).distanceFromEdge() > 0; i++)
            if
            (
                position.turn.forBlack() and
                position.isWhite(square.downLeft(i)) and
                position.isEmpty(square.downLeft(i + 1))
            )
            {
                moves.push_back(Move(square, square.downLeft(i + 1), square.downLeft(i)));
                capturePossible = true;
                break;
            }
            else if 
            (
                position.isWhite(square.downLeft(i)) and
                position.isWhite(square.downLeft(i+1))
            )
            {
                break;
            } 
    }

    void checkCaptureUpLeft(const Position& position)
    {
        for (int i = 1; square.upLeft(i).distanceFromEdge() > 0; i++)
            if
            (
                position.turn.forWhite() and
                position.isBlack(square.upLeft(i)) and
                position.isEmpty(square.upLeft(i + 1))
            )
            {
                moves.push_back(Move(square, square.upLeft(i + 1), square.upLeft(i)));
                capturePossible = true;
                break;
            }
            else if 
            (
                position.isBlack(square.upLeft(i)) and
                position.isBlack(square.upLeft(i+1))
            )
            {
                break;
            } 

        for (int i = 1; square.upLeft(i).distanceFromEdge() > 0; i++)
            if
            (
                position.turn.forBlack() and
                position.isWhite(square.upLeft(i)) and
                position.isEmpty(square.upLeft(i + 1))
            )
            {
                moves.push_back(Move(square, square.upLeft(i + 1), square.upLeft(i)));
                capturePossible = true;
                break;
            }
            else if 
            (
                position.isWhite(square.upLeft(i)) and
                position.isWhite(square.upLeft(i+1))
            )
            {
                break;
            } 
    }

    void checkMoveUpRight(const Position& position)
    {
        for (int i=1; square.upRight(i).distanceFromEdge() > -1; i++)
        {
            if
            (
                position.turn.forWhite() and
                position.isEmpty(square.upRight(i)) 
            )
            {
                moves.push_back(Move(square, square.upRight(i)));
            }
            else
            {
                break;
            }
            
        }
        
        for (int i=1; square.upRight(i).distanceFromEdge() > -1; i++)
        {
            if
            (
                position.turn.forBlack() and
                position.isEmpty(square.upRight(i))
            )
            {
                moves.push_back(Move(square, square.upRight(i)));
            }
            else 
            {
                break;
            }
        }

    }

    void checkMoveDownRight(const Position& position)
    {
        for (int i=1; square.downRight(i).distanceFromEdge() > -1; i++)
        {
            if
            (
                position.turn.forWhite() and
                position.isEmpty(square.downRight(i)) 
            )
            {
                moves.push_back(Move(square, square.downRight(i)));
            }
            else
            {
                break;
            }
            
        }
        
        for (int i=1; square.downRight(i).distanceFromEdge() > -1; i++)
        {
            if
            (
                position.turn.forBlack() and
                position.isEmpty(square.downRight(i))
            )
            {
                moves.push_back(Move(square, square.downRight(i)));
            }
            else 
            {
                break;
            }
        }

    }

    void checkMoveDownLeft(const Position& position)
    {
        for (int i=1; square.downLeft(i).distanceFromEdge() > -1; i++)
        {
            if
            (
                position.turn.forWhite() and
                position.isEmpty(square.downLeft(i))
            )
            {
                moves.push_back(Move(square, square.downLeft(i)));
            }
            else 
            {
                break;
            }
            
        }
        
        for (int i=1; square.downLeft(i).distanceFromEdge() > -1; i++)
        {
            if
            (
                position.turn.forBlack() and
                position.isEmpty(square.downLeft(i))
            )
            {
                moves.push_back(Move(square, square.downLeft(i)));
            }
            else
            {
                break;
            }
            
        }

    }

    void checkMoveUpLeft(const Position& position)
    {
        for (int i=1; square.upLeft(i).distanceFromEdge() > -1; i++)
        {
            if
            (
                position.turn.forWhite() and
                position.isEmpty(square.upLeft(i))
            )
            {
                moves.push_back(Move(square, square.upLeft(i)));
            }
            else 
            {
                break;
            }
            
        }
        
        for (int i=1; square.upLeft(i).distanceFromEdge() > -1; i++)
        {
            if
            (
                position.turn.forBlack() and
                position.isEmpty(square.upLeft(i))
            )
            {
                moves.push_back(Move(square, square.upLeft(i)));
            }
            else
            {
                break;
            }
            
        }

    }

};
