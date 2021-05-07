#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "piece.hpp"

#ifndef KING_H
#define KING_H

class King : public Piece
{
    public:
        King(int x, int y, string name, const char* filename, SDL_Renderer* renderer);
};
#endif