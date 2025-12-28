#pragma once

struct Turn
{
    int turn=1; //white starts

    bool forWhite()
    {
        return (turn == 1);
    }
    bool forBlack()
    {
        return (turn == 0);
    }
    void end()
    {
        if (turn == 1)
        {
            turn = 0;
        }
        if (turn == 0)
        {
            turn ==1;
        }
    }
};
