#pragma once

#include "../square.hpp"

struct Move
{
    Square origin;
    Square destination;

    Move(Square origin_init, Square destination_init):
        origin(origin_init),
        destination(destination_init)
    {};

    bool operator==(const Move& move) const
    {
        return origin.square_id == move.origin.square_id && destination.square_id == move.destination.square_id;
    }
};
