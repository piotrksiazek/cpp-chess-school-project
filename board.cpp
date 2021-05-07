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

void Board::initBoard()
{
    int counter=0;
   /*Iteruję przez wiersze*/ 
   for(int y=0; y<SQUARES_PER_ROW; y++)
   {
        /*Iteruję przez kolumny*/ 
        for (int x=0; x<SQUARES_PER_ROW; x++)
        {
            SDL_Rect rect;
            if(++counter % 2 == 0)
            {
                this->board[y][x].addProps(x, y, WHITE, this->renderer);
                King king(x, y, "king", "king.png", this->renderer);
                // this->board[y][x].piece = king;
                // this->board[y][x].piece->render(&this->board[y][x].rectangle);
                SDL_Surface *image;
                image = IMG_Load("king.png");
                SDL_Texture* image_texture = SDL_CreateTextureFromSurface(renderer, image);
                SDL_RenderCopy(this->renderer, king.image_texture, nullptr, &this->board[y][x].rectangle);
            }
            else
                this->board[y][x].addProps(x, y, BLACK, this->renderer);
        }
        counter--;
       
   }
   SDL_RenderPresent(renderer);
}