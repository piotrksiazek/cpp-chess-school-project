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
    this->checkHorizontalAndVertical(positions, currentPosition);
    this->checkDiagonal(positions, currentPosition);
    /*for (auto& position : positions)
    {
        cout << "x: " << position.x << endl << "y: " << position.y << endl;
    }*/
    return positions;
}