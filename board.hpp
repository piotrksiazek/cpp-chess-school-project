#include <string>
#include "square.hpp"
#include "constants.hpp"

using namespace std;
#ifndef CHESSBOARD
#define CHESSBOARD
class Board
{
    public:
        SDL_Renderer* renderer;
        int numberOfSquares;
        Square board[SQUARES_PER_ROW][SQUARES_PER_ROW];
        Board(SDL_Renderer* renderer);
        void initBoard();
};
#endif