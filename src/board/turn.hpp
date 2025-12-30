#pragma once

struct Turn
{
    int turn=1; //white starts

    bool forWhite() const
    {
        return (turn == 1);
    }
    bool forBlack() const
    {
        return (turn == 0);
    }
    void end()
    {
        if (turn == 1)
        {
            turn = 0;
        }
        else if (turn == 0)
        {
            turn = 1;
        }
    }
};
