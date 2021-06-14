#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "piece.hpp"

#ifndef KNIGHT_H
#define KNIGHT_H

class Knight : public Piece
{
public:
    Knight(int x, int y, string name, const char* filename, SDL_Renderer* renderer, char color);
    vector<Position> getPossibleMoves();

private:
    void addToPositionsIfInBoundaries(vector<Position>& positions, Position currentPosition, int moveX, int moveY);
};
#endif



