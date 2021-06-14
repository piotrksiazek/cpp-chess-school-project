#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "piece.hpp"

#ifndef QUEEN_H
#define QUEEN_H

class Queen : public Piece
{
public:
    Queen(int x, int y, string name, const char* filename, SDL_Renderer* renderer);
    vector<Position> getPossibleMoves();
};
#endif
