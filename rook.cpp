#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <vector>
#include "position.hpp"
#include "piece.hpp"
#include "rook.hpp"
#include "utils.hpp"

Rook::Rook(int x, int y, string name, const char* filename, SDL_Renderer* renderer, char color)
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

vector<Position> Rook::getPossibleMoves()
{
    vector<Position> positions;
    Position currentPosition = { this->position.x, this->position.y };
    this->checkHorizontalAndVertical(positions, currentPosition);
    return positions;
}