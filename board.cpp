#include <iostream>
#include <typeinfo>
#include "board.hpp"
#include "constants.hpp"
#include "square.hpp"
#include "king.hpp"
#include "Queen.hpp"
#include "piece.hpp"
#include "pawn.hpp"
using namespace std;

Board::Board(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    initBoard();
};

void Board::populatePieces()
{
    //black king
    // Piece *b_king = new King(4, 0, "b_king", "images/b_king.png", this->renderer);
    // this->board[b_king->y][b_king->x].piece = b_king;
    // this->pieces.push_back(b_king);
    for (int i = 0; i < 8; i++)
    {
        //black pawns
        this->addPiece<Pawn>(i, 1, "b_pawn", "images/b_pawn.png", 'b');

        //white pawns
        this->addPiece<Pawn>(i, 6, "w_pawn", "images/w_pawn.png", 'w');
    }

    this->addPiece<King>(4, 0, "b_king", "images/b_king.png", 'b');
    this->addPiece<King>(4, 7, "w_king", "images/w_king.png", 'w');

    this->addPiece<Queen>(3, 0, "b_queen", "images/b_queen.png", 'b');
    this->addPiece<Queen>(3, 7, "w_queen", "images/w_queen.png", 'w');
    // //white king
    // Piece *w_king = new King(4, 7, "w_king", "images/w_king.png", this->renderer);
    // this->board[w_king->y][w_king->x].piece = w_king;
    // this->board[w_king->y][w_king->x].piece->render(&this->board[w_king->y][w_king->x].rectangle);
    // this->pieces[index++] = w_king;

    // //black queen
    // Piece *b_queen = new King(3, 0, "b_queen", "images/b_queen.png", this->renderer);
    // this->board[b_queen->y][b_queen->x].piece = b_queen;
    // this->board[b_queen->y][b_queen->x].piece->render(&this->board[b_queen->y][b_queen->x].rectangle);
    // this->pieces[index++] = b_queen;
}

void Board::initBoard()
{
    int counter=0;
   /*Iteruję przez wiersze*/ 
   for(int y=0; y<SQUARES_PER_ROW; y++)
   {
        /*Iteruję przez kolumny*/ 
        for (int x=0; x<SQUARES_PER_ROW; x++)
        {
            // Piece *king = new King(x, y, "king", "images/b_king.png", this->renderer);
            // this->board[y][x].piece = king;
            SDL_Rect rect;
            if(++counter % 2 == 0)
            {
                this->board[y][x].addProps(x, y, WHITE, this->renderer);
                // this->board[y][x].piece->render(&this->board[y][x].rectangle);
            }
            else
                this->board[y][x].addProps(x, y, BLACK, this->renderer);
        }
        counter--;
       
   }
   SDL_RenderPresent(renderer);
}

void Board::renderPieces()
{
    for(Piece *piece : this->pieces)
    {
        piece->render(&piece->rectangle);
    }
}

template <class T>
void Board::addPiece(int x, int y, string name, const char* filename, char color)
{
    Piece *new_piece = new T(x, y, name, filename, this->renderer, color);
    this->board[new_piece->position.y][new_piece->position.x].piece = new_piece;
    this->pieces.push_back(new_piece);
}

void Board::movePieceToPosition(Piece *piece, Position position)
{
    /*Piece* new_piece = new T(x, y, name, filename, this->renderer);
    this->board[new_piece->y][new_piece->x].piece = new_piece;
    this->pieces.push_back(new_piece);*/
    Piece* currentPiece = piece; //save reference
    this->board[position.y][position.x].piece = piece; //move reference to the new square
    this->board[piece->position.y][piece->position.x].piece = (Piece*)nullptr; //delete reference on current position
    piece->rectangle.x = position.x * RECT_SIZE;
    piece->rectangle.y = position.y * RECT_SIZE;
    piece->position = position;
    piece->isFirstMove = false;
}