#pragma once

#include "move.hpp"
#include "legal_checker_moves.hpp"
#include "legal_king_moves.hpp"

struct LegalMoves 
{
    std::vector< std::vector<Move> > moves;
    bool capturePossible = false;

    LegalMoves(const Position& position)
    {
        for (int i=0; i<100; i++)
        {
        LegalCheckerMoves legal_checker_moves = LegalCheckerMoves(Square(i), position);
            moves.push_back(legal_checker_moves.moves);
            if (legal_checker_moves.capturePossible)
            {
                capturePossible = true;
            }

        LegalKingMoves legal_king_moves = LegalKingMoves(Square(i), position);
            moves.push_back(legal_king_moves.moves);
            if (legal_king_moves.capturePossible)
            {
                capturePossible = true;
            }
        }
    }

};