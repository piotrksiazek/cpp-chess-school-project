#include <iostream>
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "position.hpp"
using namespace std;

#ifndef PIECE_H
#define PIECE_H

class Piece
{
    public:
        int x, y; //coordinates
        Position position;
        string name;
        const char* filename;
        SDL_Texture* image_texture;
        SDL_Renderer* renderer;
        SDL_Rect rectangle;
        Piece();
        virtual ~Piece() {};
        void render(SDL_Rect *rectangle); //TODO później zmień to na friend
        void loadTexture();
        void print();
        virtual vector<Position> getPossibleMoves();
        bool isFirstMove;
        char color;
    protected:
        void createRect();
        bool isInBoundaries(int x, int y, Position currentPosition);
        void checkDiagonal(vector<Position> &positions, Position currentPosition);
        void checkHorizontalAndVertical(vector<Position> &positions, Position currentPosition);
        void filterOutObstacles(vector<Position> positions, Position currentPosition);
};

#endif