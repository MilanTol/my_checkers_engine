#pragma once

#include "move.hpp"
#include "legal_moves_from_square.hpp"

struct LegalMoves 
{
    std::vector< std::vector<Move> > moves;
    bool capturePossible = false;

    LegalMoves(const Position& position)
    {
        for (int i=0; i<100; i++)
        {
        LegalMovesFromSquare legal_moves_from_square = LegalMovesFromSquare(Square(i), position);
            moves.push_back(legal_moves_from_square.moves);
            if (legal_moves_from_square.capturePossible)
            {
                capturePossible = true;
            }
        }
    }

};