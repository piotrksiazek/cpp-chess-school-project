#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "piece.hpp"

#ifndef ROOK_H
#define ROOK_H

class Rook : public Piece
{
public:
    Rook(int x, int y, string name, const char* filename, SDL_Renderer* renderer, char color);
    vector<Position> getPossibleMoves();
};
#endif

