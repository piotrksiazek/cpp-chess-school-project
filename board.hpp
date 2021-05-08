#include <string>
#include "square.hpp"
#include "constants.hpp"
#include "piece.hpp"

using namespace std;
#ifndef CHESSBOARD
#define CHESSBOARD
class Board
{
    public:
        SDL_Renderer* renderer;
        int numberOfSquares;
        Square board[SQUARES_PER_ROW][SQUARES_PER_ROW];
        // Square ***board = new Square**[20];
        Piece *pieces[32];
        Board(SDL_Renderer* renderer);
        void initBoard();
        void renderPieces();
    // private:
        void populatePieces();
};
#endif