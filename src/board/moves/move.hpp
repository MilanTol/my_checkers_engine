#pragma once

#include "../square.hpp"

struct Move
{
    Square origin;
    Square destination;

    Move(Square origin_init, Square desination_init):
        origin(origin_init),
        destination(desination_init)
    {};

    bool operator==(const Move& move) const
    {
        return origin.square_id == move.origin.square_id && destination.square_id == move.destination.square_id;
    }
};
