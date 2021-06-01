#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "position.hpp"
using namespace std;

#ifndef PIECE_H
#define PIECE_H

class Piece
{
    public:
        int x, y; //coordinates

        string name;
        const char* filename;
        SDL_Texture* image_texture;
        SDL_Renderer* renderer;
        SDL_Rect rectangle;
        Piece();
        void render(SDL_Rect *rectangle); //TODO później zmień to na friend
        void loadTexture();
        void print();
        virtual vector<Position> getPossibleMoves();
    protected:
        void createRect();
};

#endif