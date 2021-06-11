#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <vector>
#include "position.hpp"
#include "piece.hpp"
#include "king.hpp"
#include "utils.hpp"

King::King(int x, int y, string name, const char* filename, SDL_Renderer* renderer)
{
    this->x=x;
    this->y=y;
    this->name=name;
    this->filename=filename;
    this->renderer=renderer;
    loadTexture();
    createRect();
}

vector<Position> King::getPossibleMoves()
{
    vector<Position> positions;
    Position currentPosition = {this->x, this->y};
    for(int x=-1; x<=1; x++)
    {
        for(int y=-1; y<=1; y++)
        {
            int moveX = currentPosition.x + x;
            int moveY = currentPosition.y + y;
            if(moveX < 8 && moveX >= 0 && moveY < 8 && moveY >= 0 && (moveX != currentPosition.x || moveY != currentPosition.y))
            {
                Position newPossiblePosition = {moveX, moveY};
                positions.push_back(newPossiblePosition);
            }
        }
    }
    // for(auto& position : positions)
    // {
    //     cout<<"x: " <<position.x << endl << "y: " << position.y << endl;
    // }
    return positions;
}