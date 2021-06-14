#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "piece.hpp"

#ifndef PAWN_H
#define PAWN_H

class Pawn : public Piece
{
public:
    Pawn(int x, int y, string name, const char* filename, SDL_Renderer* renderer, char color);
    vector<Position> getPossibleMoves();
};
#endif
