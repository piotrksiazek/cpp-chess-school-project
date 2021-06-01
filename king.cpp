#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
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
    cout<<"possible moves"<<endl;
    return positions;
}