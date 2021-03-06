#include <SDL.h>
#include "piece.hpp"

#ifndef SQUARE_H
#define SQUARE_H
class Square
{
    public:
        Piece *piece;
        bool isFree;
        SDL_Rect rectangle;
        SDL_Renderer* renderer;
        int x;
        int y;
        int r; int g; int b; int a;
        Square();
        void addProps(int x, int y, int r, int g, int b, int a, SDL_Renderer* renderer);
        SDL_Rect createRect(int x, int y);
        void print();
        void setColor(int r, int g, int b, int a);
};
#endif