#pragma once

struct EmptySquares
{

    bool empty_squares[100];

    EmptySquares()
    {
        for (int i=0; i<100; i++)
        {
            empty_squares[i] = false;
        }
        for (int column = 1; column < 10; column += 2) //empty row 4
        {
            setEmpty(4, column, true);
        }
        for (int column = 0; column < 10; column += 2) //empty row 5
        {
            setEmpty(5, column, true);
        }
    }

    int rcToSquare(int row, int column)
    {
        return 10*row + column;
    }

    void setEmpty(int row, int column, bool empty)
    {
        empty_squares[rcToSquare(row, column)] = empty;
    }

    void setEmpty(int square, bool empty)
    {
        empty_squares[square] = empty;
    }

    bool isEmpty(int row, int column)
    {
        return empty_squares[rcToSquare(row, column)];
    }

    bool isEmpty(int square)
    {
        return empty_squares[square];
    }
};
