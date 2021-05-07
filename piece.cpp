#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "piece.hpp"

using namespace std;
Piece::Piece()
{
    // this->x=x;
    // this->y=y;
    // this->name=name;
    // this->filename=filename;
    // this->renderer=renderer;
    // loadTexture();
}

void Piece::loadTexture()
{
    SDL_Surface *image;
    image = IMG_Load(this->filename);
    this->image_texture = SDL_CreateTextureFromSurface(this->renderer, image);
}

void Piece::loadMembers()
{
    this->x=x;
    this->y=y;
    this->name=name;
    this->filename=filename;
    this->renderer=renderer;
    loadTexture();
}