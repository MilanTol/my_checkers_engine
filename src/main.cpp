#include <SFML/Graphics.hpp>
#include <iostream>

#include "user_interface/events.hpp"
#include "user_interface/input.hpp"

#include "config.hpp"

#include "board/square.hpp"
#include "board/position.hpp"
#include "board/dynamic_position.hpp"
#include "board/moves/legal_checker_moves.hpp"
#include "board/moves/legal_moves.hpp"

#include "graphics/draw_board.hpp"
#include "graphics/draw_checkers.hpp"
#include "graphics/draw_kings.hpp"
#include "graphics/draw_legal_move.hpp"

Square positionToSquare(sf::Vector2i position)
{
    int column = static_cast<int>( position.x / (cfg::window_size.x/10) ); //this rounds down in c++
    int row = static_cast<int>( position.y / (cfg::window_size.y/10) );
    return Square(10*row + column);
}

Input input;
Square clicked_square = Square(-1);

DynamicPosition position = DynamicPosition(Position());

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({cfg::window_size.x, cfg::window_size.y}), "Let's play checkers!");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {   
        processEvents(window, input);
        
        if (input.mouseClicked and clicked_square.square_id == -1) // if clicked
        {   
            clicked_square = positionToSquare(sf::Mouse::getPosition(window));
        }

        if (input.mouseReleased and clicked_square.square_id != -1) //if released
        {   
            Square released_square = positionToSquare(sf::Mouse::getPosition(window));
            Move suggested_move = Move(clicked_square, released_square);
            
            std::vector<Move> legal_checker_moves = LegalCheckerMoves(clicked_square, position).moves;
            std::vector<Move> legal_king_moves = LegalKingMoves(clicked_square, position).moves;

            LegalMoves legal_moves = LegalMoves(position);
            
            for (Move move : legal_checker_moves)
            {
                if (!move.isCapture() && legal_moves.capturePossible)
                    continue;
                if (suggested_move == move)
                    position.execute_move(move);
            }

            for (Move move : legal_king_moves)
            {   
                if (!move.isCapture() && legal_moves.capturePossible)
                    continue;
                if (suggested_move == move)
                    position.execute_move(move);
            }
                                    
            clicked_square = Square(-1);
            input.mouseClicked = false;
            input.mouseReleased = false;
        }
        
        window.clear();

        drawBoard(window);
        drawCheckers(window, position);
        drawKings(window, position);

        if (input.mouseClicked) //draw legal moves
        {
            if (position.isWhiteChecker(clicked_square) && position.turn.forWhite())
            {   
                drawWhiteChecker(window, sf::Mouse::getPosition(window));
            }
            if (position.isBlackChecker(clicked_square) && position.turn.forBlack())
            {
                drawBlackChecker(window, sf::Mouse::getPosition(window));
            }
            if (position.isWhiteKing(clicked_square) && position.turn.forWhite())
            {
                drawWhiteKing(window, sf::Mouse::getPosition(window));
            }
            if (position.isBlackKing(clicked_square) && position.turn.forBlack())
            {
                drawBlackKing(window, sf::Mouse::getPosition(window));
            }

            LegalMoves legal_moves = LegalMoves(position);

            std::vector<Move> legal_checker_moves = LegalCheckerMoves(clicked_square, position).moves;
            for (Move move : legal_checker_moves)
            {
                if (!move.isCapture() && legal_moves.capturePossible)
                    continue;
                drawLegalMove(window, move);
            }

            std::vector<Move> legal_king_moves = LegalKingMoves(clicked_square, position).moves;
            for (Move move : legal_king_moves)
            {
                if (!move.isCapture() && legal_moves.capturePossible)
                    continue;
                drawLegalMove(window, move);
            }
        }

        window.display();
    }
}
