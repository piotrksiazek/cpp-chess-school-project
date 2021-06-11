#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "piece.hpp"

#ifndef KING_H
#define KING_H

class King : public Piece
{
    public:
        King(int x, int y, string name, const char* filename, SDL_Renderer* renderer);
        vector<Position> getPossibleMoves();
};
#endif