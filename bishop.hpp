#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "piece.hpp"

#ifndef BISHOP_H
#define BISHOP_H

class Bishop : public Piece
{
public:
    Bishop(int x, int y, string name, const char* filename, SDL_Renderer* renderer, char color);
    vector<Position> getPossibleMoves();
};
#endif


