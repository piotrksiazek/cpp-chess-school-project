#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

#ifndef PIECE_H
#define PIECE_H

class Piece
{
    public:
        string name;
        const char* filename;
        SDL_Texture* image_texture;
        SDL_Renderer* renderer;
        bool isFirstMove; //for pawns
        Piece(int x, int y, string name, const char* filename, SDL_Renderer* renderer);
        void render(SDL_Rect *rectangle); //TODO później zmień to na friend

    private:
        void loadTexture(); 
};

#endif