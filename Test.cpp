/**
 * Unit tests.
 * AUTHORS: <Lioz Akirav>
 * Date: 2021-03
 */

#include "doctest.h"
#include "Board.hpp"
#include <string>
#include <climits>
using namespace std;
using namespace ariel;

Board board; // Initializes an empty board for the first scenario
Board board_2; // Initializes an empty board for the second scenario
Board board_3; // Initializes an empty board for the third scenario

TEST_CASE("Checks the post and read functions - Vertical")
{
    /* Direction: Vertical */
    board.post(0, 0, Direction::Vertical, "Checks the post and read functions");

    /* Assert True */
    CHECK(board.read(0, 0, Direction::Vertical, 6) == "Checks");
    CHECK(board.read(7, 0, Direction::Vertical, 3) == "the");
    CHECK(board.read(11, 0, Direction::Vertical, 4) == "post");
    CHECK(board.read(16, 0, Direction::Vertical, 3) == "and");
    CHECK(board.read(20, 0, Direction::Vertical, 8) == "function");
    CHECK(board.read(29, 0, Direction::Vertical, 2) == "on");
    CHECK(board.read(32, 0, Direction::Vertical, 1) == "a");
    CHECK(board.read(34, 0, Direction::Vertical, 6) == "filled");
    CHECK(board.read(41, 0, Direction::Vertical, 5) == "board");
}

TEST_CASE("Checks the post and read functions - Horizontal")
{
    /* Direction: Horizontal */
    board.post(0, 0, Direction::Horizontal, "Checks the post and read functions");

    /* Assert True */
    CHECK(board.read(0, 0, Direction::Horizontal, 6) == "Checks");
    CHECK(board.read(0, 7, Direction::Horizontal, 3) == "the");
    CHECK(board.read(0, 11, Direction::Horizontal, 4) == "post");
    CHECK(board.read(0, 16, Direction::Horizontal, 3) == "and");
    CHECK(board.read(0, 15, Direction::Horizontal, 8) == "function");
    CHECK(board.read(0, 24, Direction::Horizontal, 2) == "on");
    CHECK(board.read(0, 27, Direction::Horizontal, 1) == "a");
    CHECK(board.read(0, 29, Direction::Horizontal, 6) == "filled");
    CHECK(board.read(0, 35, Direction::Horizontal, 5) == "board");
}

TEST_CASE("Checks the read function on an empty board - Vertical")
{
    /* Direction: Vertical */

    /* Assert True */
    CHECK(board_2.read(0, 0, Direction::Vertical, 0) == "");
    CHECK(board_2.read(1, 1, Direction::Vertical, 1) == "_");
    CHECK(board_2.read(2, 2, Direction::Vertical, 2) == "__");
    CHECK(board_2.read(40, 400, Direction::Vertical, 4) == "____");
}

TEST_CASE("Checks the read function on an empty board - Horizontal")
{
    /* Direction: Horizontal */

    /* Assert True */
    CHECK(board_2.read(0, 0, Direction::Horizontal, 0) == "");
    CHECK(board_2.read(1, 1, Direction::Horizontal, 1) == "_");
    CHECK(board_2.read(2, 2, Direction::Horizontal, 2) == "__");
    CHECK(board_2.read(40, 400, Direction::Horizontal, 4) == "____");
}

TEST_CASE("Checks override posts - Vertical + Horizontal")
{
    /* Direction: Vertical */
    // First phrase 
    board_3.post(0, 0, Direction::Vertical, "Easy peasy");
    board_3.post(0, 0, Direction::Horizontal, "lemon squeezy");
     // Second phrase(override)
    board_3.post(0, 0, Direction::Vertical, "Okey");
    board_3.post(0, 0, Direction::Horizontal, "dokey");

    /* Assert True */
    CHECK(board_3.read(0, 0, Direction::Vertical, 10) == "dkey peasy");
    CHECK(board_3.read(0, 0, Direction::Horizontal, 13) == "dokey squeezy");
}