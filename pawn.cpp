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
    Position possiblePositions[3];
    if (this->color == 'b')
    {
        int moveY;
        if (this->isFirstMove)
        {
            positions.push_back({currentPosition.x, currentPosition.y + 2 });
            positions.push_back({ currentPosition.x, currentPosition.y + 1 });
        }
        else
        {
            possiblePositions[0] = { currentPosition.x, currentPosition.y + 1 };
            possiblePositions[1] = { currentPosition.x - 1, currentPosition.y + 1 };
            possiblePositions[2] = { currentPosition.x + 1, currentPosition.y + 1 };
            for (int i = 0; i < 3; i++)
            {
                if (isInBoundaries(possiblePositions[i].x, possiblePositions[i].y, currentPosition))
                {
                    positions.push_back(possiblePositions[i]);
                }
            }
        }
    }
    else
    {
        int moveY;
        if (this->isFirstMove)
        {
            positions.push_back({ currentPosition.x, currentPosition.y - 2 });
            positions.push_back({ currentPosition.x, currentPosition.y - 1 });
        }
        else
        {
            possiblePositions[0] = { currentPosition.x, currentPosition.y - 1 };
            possiblePositions[1] = { currentPosition.x - 1, currentPosition.y - 1 };
            possiblePositions[2] = { currentPosition.x + 1, currentPosition.y - 1 };
            for (int i = 0; i < 3; i++)
            {
                if (isInBoundaries(possiblePositions[i].x, possiblePositions[i].y, currentPosition))
                {
                    positions.push_back(possiblePositions[i]);
                }
            }
        }
    }
    return positions;
}