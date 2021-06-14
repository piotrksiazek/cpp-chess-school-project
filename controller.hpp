#include <iostream>
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "board.hpp"
#include "piece.hpp"
#include "utils.hpp"

#ifndef CONTROLLER_H
#define CONTROLLER_H
class Controller
{
    public:
        Piece* selectedPiece;
        Controller(Board *board, int * squareX, int *squareY, SDL_Event *event);
        Piece * GetPieceOnMouseOver();
        int *squareX;
        int *squareY;
        Board *board; //pointer to board object
        vector<Position> possibleMoves;
        vector<Position> getPossibleMoves();
        bool isChoosenRectInPossibleMoves(Position position);
    private:
        SDL_Event *event;
        bool choosingPosition;
        
};

#endif