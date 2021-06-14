#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <vector>
#include "position.hpp"
#include "piece.hpp"
#include "pawn.hpp"
#include "utils.hpp"


Pawn::Pawn(int x, int y, string name, const char* filename, SDL_Renderer* renderer, char color)
{
    this->position.x = x;
    this->position.y = y;
    this->name = name;
    this->filename = filename;
    this->renderer = renderer;
    this->color = color;
    this->isFirstMove = true;
    loadTexture();
    createRect();
}

vector<Position> Pawn::getPossibleMoves()
{
    vector<Position> positions;
    Position currentPosition = { this->position.x, this->position.y };
    /*if (this->isFirstMove)
    {
        if (this->color == 'w')
            moveY = this->position.y - 2;
        else if (this->color == 'b')
            moveY = this->position.y + 2;
        if (isInBoundaries(this->position.x, moveY, this->position))
            positions.push_back({ this->position.x, moveY });
    }
    else
    {
        if (this->color == 'b')
            moveY = this->position.y - 1;
        else if (this->color == 'b')
            moveY = this->position.y + 1;
        if (isInBoundaries(this->position.x, moveY, this->position))
            positions.push_back({ this->position.x, moveY });
    }*/
    if (this->color == 'b')
    {
        int moveY;
        if (this->isFirstMove)
            moveY = currentPosition.y + 2;
        else
            moveY = currentPosition.y+1;
        if (isInBoundaries(this->position.x, moveY, currentPosition))
        {
            Position newPosition = { currentPosition.x, moveY };
            positions.push_back(newPosition);
        }
    }
    else
    {
        int moveY;
        if (this->isFirstMove)
            moveY = currentPosition.y - 2;
        else
            moveY = currentPosition.y - 1;
        if (isInBoundaries(this->position.x, moveY, currentPosition))
            positions.push_back({ this->position.x, moveY });
    }
    return positions;
}