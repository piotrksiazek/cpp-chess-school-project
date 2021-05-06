#include <iostream>
#include "board.hpp"
#include "constants.hpp"
#include "square.hpp"
using namespace std;

Board::Board(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    initBoard();
};

void Board::initBoard()
{
   /*Iteruję przez wiersze*/ 
   for(int y=0; y<SQUARES_PER_ROW; y++)
   {
        /*Iteruję przez kolumny*/ 
        for (int x=0; x<SQUARES_PER_ROW; x++)
        {
            SDL_Rect rect;
            this->board[y][x].addProps(x, y, WHITE, this->renderer);
            this->board[y][x].print();
        }
       
   }
   SDL_RenderPresent(renderer);
}