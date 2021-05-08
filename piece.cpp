#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "piece.hpp"
#include "constants.hpp"

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
    if(!image) cout<<"no image"<<endl;
    this->image_texture = SDL_CreateTextureFromSurface(this->renderer, image);
}

void Piece::render(SDL_Rect *rectangle)
{
    SDL_RenderCopy(this->renderer, this->image_texture, nullptr, rectangle);
}

void Piece::createRect()
{
    SDL_Rect r;
    r.x = this->x * RECT_SIZE;
    r.y = this->y * RECT_SIZE;
    r.w = RECT_SIZE;
    r.h = RECT_SIZE;
    this->rectangle=r;
}
