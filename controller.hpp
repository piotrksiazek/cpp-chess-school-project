#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "board.hpp"
#include "piece.hpp"
#include "utils.hpp"

#ifndef CONTROLLER_H
#define CONTROLLER_H
class Controller
{
    public:
        Controller(Board *board, int * squareX, int *squareY);
        Piece * GetPieceOnMouseOver();
        int *squareX;
        int *squareY;
    // private:
        Board *board; //pointer to board object
        vector<Position> getPossibleMoves();
        
};

#endif