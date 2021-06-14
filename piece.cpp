#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <vector>
#include "utils.hpp"
#include "piece.hpp"
#include "constants.hpp"
#include "position.hpp"

using namespace std;
Piece::Piece()
{
    //watch out
    //this->x=x;
    //this->y=y;
   // this->name=name;
   // this->filename=filename;
   // this->renderer=renderer;
  //  loadTexture();
}
vector<Position> Piece::getPossibleMoves() 
{
    vector<Position> position;
    return position;
}

void Piece::loadTexture()
{
    SDL_Surface *image;
    image = IMG_Load(this->filename);
    if(!image) cout<<"no image"<<endl;
    this->image_texture = SDL_CreateTextureFromSurface(this->renderer, image);
}

void Piece::render(SDL_Rect *rectangle)
{
    SDL_RenderCopy(this->renderer, this->image_texture, nullptr, rectangle);
}

void Piece::createRect()
{
    SDL_Rect r;
    r.x = this->position.x * RECT_SIZE;
    r.y = this->position.y * RECT_SIZE;
    r.w = RECT_SIZE;
    r.h = RECT_SIZE;
    this->rectangle=r;
}

bool Piece::isInBoundaries(int moveX, int moveY, Position currentPosition)
{
    return (moveX < 8 && moveX >= 0 && moveY < 8 && moveY >= 0 && (moveX != currentPosition.x || moveY != currentPosition.y));
}

void Piece::checkHorizontalAndVertical(vector<Position> &positions, Position currentPosition)
{
    int moveX, moveY;
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
    }
}

void Piece::checkDiagonal(vector<Position>& positions, Position currentPosition)
{
    int moveX, moveY;
    int y = -7;
    for (int x = -7; x <= 7; x++)
    {
        //first diagonal
        moveX = currentPosition.x + x;
        moveY = currentPosition.y + y;
        if (isInBoundaries(moveX, moveY, currentPosition))
        {
            Position newpossibleposition = { moveX, moveY };
            positions.push_back(newpossibleposition);
        }
        //second diagonal
        moveX = currentPosition.x + x;
        moveY = currentPosition.y - y;
        if (isInBoundaries(moveX, moveY, currentPosition))
        {
            Position newpossibleposition = { moveX, moveY };
            positions.push_back(newpossibleposition);
        }
        y++;
    }
}

void Piece::print()
{
    cout<< endl << "Name: " << this->name << endl;
    cout<<"Position x: " << this->x << endl;
    cout<<"Position y: " << this->y << endl << endl;
}
