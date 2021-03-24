#include "Board.hpp"
#include <iostream>
#include <climits>

using namespace std;
const char blank_cell = '_';
uint min_row = 0;
uint max_row = 0;
uint min_col = 0;
uint max_col = 0;

namespace ariel
{
    // bool Board::checkSize(uint row, uint col)
    // {
    //     bool ans = false;
    //     uint num_rows = max_row - min_row;
    //     uint num_cols = max_col - min_col;
    //     return true;
    // }

    // This function increase the size of the board
    void Board::boardResize(uint row, uint col)
    {
        this->rows = row;
        this->columns = col;
        this->board.resize(row); // increases the rows

        for (int i = 0; i < row; i++)
        {
            // increases the columns of each row and initialize with blank cell
            board[i].resize(col, blank_cell);
        }
    }

    // This function post a new post in the board
    void Board::post(uint row, uint col, Direction direction, string text)
    {
        unit length = text.length;
        if (direction == Direction::Horizontal)
        {
            if ((col + length > max_col) || row > max_row)
            {
                boardResize(row, col);
            }
            for (int i = 0; i < length; i++)
            {
                this->board[row][col + i] = text[i];
            }
        }

        else
        {
            if ((col > max_col) || row + length > max_row)
            {
                boardResize(row, col);
            }
            for (int i = 0; i < length; i++)
            {
                this->board[row + i][col] = text[i];
            }
        }
    }

    // This function read a message from the board
    string Board::read(uint row, uint col, Direction direction, uint length)
    {
        string ans = "";
        if (direction == Direction::Horizontal)
        {
            if ((col + length > max_col) || row > max_row)
            {
                return blank_cell;
            }

            else
            {
                for (int i = 0; i < length; i++)
                {
                    ans += board[row][col + i] = text[i];
                }
            }
        }
        else
        {
            if ((col > max_col) || row + length > max_row)
            {
                return blank_cell;
            }

            else
            {
                for (int i = 0; i < length; i++)
                {
                    ans += board[row + i][col] = text[i];
                }
            }
        }

        return ans;
    }

    // This function print the board 
    void Board::show()
    {
        for (int i = 0; i < max_row; i++)
        {   
            for (int j = 0; j < max_col; j++)
            {
                cout << this->board[i][j];
            }
            cout << "\n";
        }
    }
}