#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <vector>
#include "position.hpp"
#include "piece.hpp"
#include "bishop.hpp"
#include "utils.hpp"

Bishop::Bishop(int x, int y, string name, const char* filename, SDL_Renderer* renderer, char color)
{
    this->position.x = x;
    this->position.y = y;
    this->name = name;
    this->filename = filename;
    this->renderer = renderer;
    this->color = color;
    loadTexture();
    createRect();
}

vector<Position> Bishop::getPossibleMoves()
{
    vector<Position> positions;
    Position currentPosition = { this->position.x, this->position.y };
    this->checkDiagonal(positions, currentPosition);
    return positions;
}