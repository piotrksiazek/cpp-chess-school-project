#include <iostream>
#include "board.hpp"
#include "constants.hpp"
#include "square.hpp"
#include "king.hpp"
#include "piece.hpp"
using namespace std;

Board::Board(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    initBoard();
};

void Board::populatePieces()
{
    //black king
    int index=0;
    Piece *b_king = new King(4, 0, "b_king", "images/b_king.png", this->renderer);
    this->board[b_king->y][b_king->x].piece = b_king;
    this->board[b_king->y][b_king->x].piece->render(&this->board[b_king->y][b_king->x].rectangle);
    this->pieces[index++] = b_king;

    //white king
    Piece *w_king = new King(4, 7, "w_king", "images/w_king.png", this->renderer);
    this->board[w_king->y][w_king->x].piece = w_king;
    this->board[w_king->y][w_king->x].piece->render(&this->board[w_king->y][w_king->x].rectangle);
    this->pieces[index++] = w_king;

    //black queen
    Piece *b_queen = new King(3, 0, "b_queen", "images/b_queen.png", this->renderer);
    this->board[b_queen->y][b_queen->x].piece = b_queen;
    this->board[b_queen->y][b_queen->x].piece->render(&this->board[b_queen->y][b_queen->x].rectangle);
    this->pieces[index++] = b_queen;
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
    for(int y=0; y<8; y++)
    {
        for(int x=0; x<8; x++)
        {
            this->board[y][x].piece->render(&this->board[y][x].rectangle);
        }
    }
}