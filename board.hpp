#include <string>
#include <vector>
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
        vector<Piece*> pieces;
        Board(SDL_Renderer* renderer);
        void initBoard();
        void renderPieces();
        void populatePieces();
        //void movePieceToPosition(Piece* piece, Position position);
    private:
        template <class T>
        void addPiece(int x, int y, string name, const char* filename);
};
#endif