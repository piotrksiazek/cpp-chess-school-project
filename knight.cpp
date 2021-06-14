#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <vector>
#include "position.hpp"
#include "piece.hpp"
#include "utils.hpp"
#include "knight.hpp"

Knight::Knight(int x, int y, string name, const char* filename, SDL_Renderer* renderer, char color)
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

void Knight::addToPositionsIfInBoundaries(vector<Position>& positions, Position currentPosition, int moveX, int moveY)
{
    if (isInBoundaries(moveX, moveY, currentPosition))
    {
        Position newPossiblePosition = { moveX, moveY };
        positions.push_back(newPossiblePosition);
    }
}

vector<Position> Knight::getPossibleMoves()
{
    vector<Position> positions;
    Position currentPosition = { this->position.x, this->position.y };
    int moveX, moveY;
    //case 1
    moveY = currentPosition.y - 2;
    moveX = currentPosition.x - 1;
    this->addToPositionsIfInBoundaries(positions, currentPosition, moveX, moveY);

    //case 2
    moveY = currentPosition.y - 2;
    moveX = currentPosition.x + 1;
    this->addToPositionsIfInBoundaries(positions, currentPosition, moveX, moveY);

    //case 3
    moveY = currentPosition.y - 1;
    moveX = currentPosition.x + 2;
    this->addToPositionsIfInBoundaries(positions, currentPosition, moveX, moveY);

    //case 4
    moveY = currentPosition.y + 1;
    moveX = currentPosition.x + 2;
    this->addToPositionsIfInBoundaries(positions, currentPosition, moveX, moveY);

    //case 5
    moveY = currentPosition.y + 2;
    moveX = currentPosition.x + 1;
    this->addToPositionsIfInBoundaries(positions, currentPosition, moveX, moveY);

    //case 6
    moveY = currentPosition.y + 2;
    moveX = currentPosition.x - 1;
    this->addToPositionsIfInBoundaries(positions, currentPosition, moveX, moveY);

    //case 7
    moveY = currentPosition.y + 1;
    moveX = currentPosition.x - 2;
    this->addToPositionsIfInBoundaries(positions, currentPosition, moveX, moveY);

    //case 8
    moveY = currentPosition.y - 1;
    moveX = currentPosition.x - 2;
    this->addToPositionsIfInBoundaries(positions, currentPosition, moveX, moveY);

    return positions;
}