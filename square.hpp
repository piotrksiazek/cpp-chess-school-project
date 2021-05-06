#include <SDL2/SDL.h>
#ifndef SQUARE_H
#define SQUARE_H
class Square
{
    public:
        SDL_Rect rectangle;
        int x;
        int y;
        int r; int g; int b; int a;
        SDL_Renderer* renderer;
        Square();
        void addProps(int x, int y, int r, int g, int b, int a, SDL_Renderer* renderer);
        SDL_Rect createRect();
        void print();
        // void setColor(int r, int g, int b, int a);
};
#endif