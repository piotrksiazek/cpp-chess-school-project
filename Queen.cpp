#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <vector>
#include "position.hpp"
#include "piece.hpp"
#include "Queen.hpp"
#include "utils.hpp"

Queen::Queen(int x, int y, string name, const char* filename, SDL_Renderer* renderer, char color)
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

vector<Position> Queen::getPossibleMoves()
{
    vector<Position> positions;
    Position currentPosition = { this->position.x, this->position.y };
    int moveX;
    int moveY;
    for (int x = -7; x <= 7; x++)
    {
        moveX = currentPosition.x + x;
        moveY = currentPosition.y + x;
        //check horizontal
        if (isInBoundaries(moveX, currentPosition.y, currentPosition))
        {
            Position newPossiblePosition = { moveX, currentPosition.y };
            positions.push_back(newPossiblePosition);
        }
        //check vertical
        if (isInBoundaries(currentPosition.x, moveY, currentPosition))
        {
            Position newPossiblePosition = { currentPosition.x, moveY };
            positions.push_back(newPossiblePosition);
        }

        //check diagonal
        for (int x = -7; x <= 7; x++)
        {
            for (int y = -7; y <= 7; y++)
            {
                moveX = currentPosition.x + x;
                moveY = currentPosition.y + y;
                if (isInBoundaries(moveX, moveY, currentPosition))
                {
                    Position newpossibleposition = { moveX, moveY };
                    positions.push_back(newpossibleposition);
                }
            }
        }
    }
    /*for (auto& position : positions)
    {
        cout << "x: " << position.x << endl << "y: " << position.y << endl;
    }*/
    return positions;
}