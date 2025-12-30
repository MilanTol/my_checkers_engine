#pragma once

#include "move.hpp"

struct Capture : Move
{
    Square captured;

    Capture(Square origin_init, Square destination_init, Square captured_init):
        Move(origin_init, destination_init),
        captured(captured_init)
    {};

    bool operator==(const Move& move) const
    {
        return origin.square_id == move.origin.square_id && destination.square_id == move.destination.square_id;
    }
};
