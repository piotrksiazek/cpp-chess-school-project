#include <iostream>
#include "board.hpp"
#include "constants.hpp"
using namespace std;

Board::Board()
{
    this->numberOfSquares = NUM_OF_SQUARES;
    cout << this->numberOfSquares << endl;
}