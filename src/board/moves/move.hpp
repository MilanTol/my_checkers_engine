#pragma once

#include "../square.hpp"

struct Move
{
    Square origin;
    Square destination;
    Square captured;

    Move(Square origin_init, Square destination_init)
        : Move(origin_init, destination_init, origin_init) //if captured square not given: set origin square as captured square
    {}

    Move(Square origin_init, Square destination_init, Square captured_init)
        : origin(origin_init),
          destination(destination_init),
          captured(captured_init)
    {}

    bool operator==(const Move& move) const
    {
        return origin.square_id == move.origin.square_id && destination.square_id == move.destination.square_id;
    }

    bool isCapture() const
    {
        return !(origin.square_id == captured.square_id);
    }
};
