#include <iostream>
#include <typeinfo>
#include "board.hpp"
#include "constants.hpp"
#include "square.hpp"
#include "king.hpp"
#include "Queen.hpp"
#include "piece.hpp"
#include "pawn.hpp"
#include "rook.hpp"
#include "bishop.hpp"
#include "knight.hpp"
using namespace std;

Board::Board(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    initBoard();
};

void Board::populatePieces()
{
    //pawns
    for (int i = 0; i < 8; i++)
    {
        //black pawns
        this->addPiece<Pawn>(i, 1, "b_pawn", "images/b_pawn.png", 'b');

        //white pawns
        this->addPiece<Pawn>(i, 6, "w_pawn", "images/w_pawn.png", 'w');
    }

    //kings
    this->addPiece<King>(4, 0, "b_king", "images/b_king.png", 'b');
    this->addPiece<King>(4, 7, "w_king", "images/w_king.png", 'w');

    //queens
    this->addPiece<Queen>(3, 0, "b_queen", "images/b_queen.png", 'b');
    this->addPiece<Queen>(3, 7, "w_queen", "images/w_queen.png", 'w');

    //rooks
    this->addPiece<Rook>(0, 0, "b_rook", "images/b_rook.png", 'b');
    this->addPiece<Rook>(7, 0, "b_rook", "images/b_rook.png", 'b');

    this->addPiece<Rook>(0, 7, "w_rook", "images/w_rook.png", 'w');
    this->addPiece<Rook>(7, 7, "w_rook", "images/w_rook.png", 'w');

    //bishops
    this->addPiece<Bishop>(2, 0, "b_boshop", "images/b_bishop.png", 'b');
    this->addPiece<Bishop>(5, 0, "b_boshop", "images/b_bishop.png", 'b');

    this->addPiece<Bishop>(2, 7, "w_boshop", "images/w_bishop.png", 'w');
    this->addPiece<Bishop>(5, 7, "w_boshop", "images/w_bishop.png", 'w');

    //knights
    this->addPiece<Knight>(1, 0, "b_knight", "images/b_knight.png", 'b');
    this->addPiece<Knight>(6, 0, "b_knight", "images/b_knight.png", 'b');

    this->addPiece<Knight>(1, 7, "w_knight", "images/w_knight.png", 'w');
    this->addPiece<Knight>(6, 7, "w_knight", "images/w_knight.png", 'w');
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
            if(++counter % 2 == 0)
            {
                this->board[y][x].addProps(x, y, WHITE, this->renderer);
                
            }
            else
                this->board[y][x].addProps(x, y, BLACK, this->renderer);
        }
        counter--;
       
   }
   SDL_RenderPresent(renderer);
}

void Board::drawBoard()
{
     int counter=0;
   /*Iteruję przez wiersze*/ 
   for(int y=0; y<SQUARES_PER_ROW; y++)
   {
        /*Iteruję przez kolumny*/ 
        for (int x=0; x<SQUARES_PER_ROW; x++)
        {
            
            if(++counter % 2 == 0)
            {
                this->board[y][x].setColor(WHITE);
            }
            else
                this->board[y][x].setColor(BLACK);
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
    this->board[new_piece->position.y][new_piece->position.x].isFree = false;
    this->pieces.push_back(new_piece);
}

void Board::movePieceToPosition(Piece *piece, Position position)
{
    Piece* currentPiece = piece; //save reference
    this->board[position.y][position.x].piece = piece; //move reference to the new square
    this->board[piece->position.y][piece->position.x].piece = (Piece*)nullptr; //delete reference on current position
    this->board[piece->position.y][piece->position.x].isFree = true; //notify square that it is free now
    this->board[position.y][position.x].isFree = false; //notify new square that it is not free now
    piece->rectangle.x = position.x * RECT_SIZE;
    piece->rectangle.y = position.y * RECT_SIZE;
    piece->position = position;
    piece->isFirstMove = false;
}

void Board::killPiece(Piece* piece)
{
    this->board[piece->position.y][piece->position.x].piece = (Piece*)nullptr; //delete reference on current position
    delete piece;
}