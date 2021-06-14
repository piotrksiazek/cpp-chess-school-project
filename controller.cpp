#include <iostream>
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "controller.hpp"
#include "constants.hpp"
#include "square.hpp"
#include "board.hpp"
#include "utils.hpp"
#include "position.hpp"

using namespace std;
Controller::Controller(Board *board, int * squareX, int *squareY, SDL_Event *event)
{
    this->board = board;
    this->squareX = squareX;
    this->squareY = squareY;
    this->event = event;
    this->choosingPosition=false;
}

Piece * Controller :: GetPieceOnMouseOver()
{
    //checks which hovered rect contains specific piece and if exists returns pointer to piece, otherwise nullptr
    Piece * pointedPiece;
    for(auto& piece: this->board->pieces)
    {
        Position position;
        position = getCurrentHoveredRect(*this->board, this->squareX, this->squareY);
        if(position.x == piece->position.x && position.y == piece->position.y)
        {
            return piece;
        }     
    }
    return (Piece *)(nullptr);
}

bool Controller::isChoosenRectInPossibleMoves(Position position)
{
    for (auto& legalPosition : this->possibleMoves) //debug
    {
        if (legalPosition.x == position.x && legalPosition.y == position.y)
            return true;
    }
    return false;
}

vector<Position> Controller :: controllerGetPossibleMoves()
//returns vector of all possible moves for selected piece
{
    Piece* piece;
    piece = this->GetPieceOnMouseOver();
    vector<Position> positions;
    if(piece != nullptr)
    {
        this->selectedPiece = piece;
        positions = selectedPiece->getPossibleMoves();
        this->choosingPosition = true;
        this->possibleMoves = positions;
    }
    else if(!this->choosingPosition)//if player clicked on an empty square, possible moves should be empty
    {
        this->possibleMoves = {};
        return {};
        
    }
    for(auto& pos : positions) //debug
    {
        changeColor(*
        this->board, pos.x, pos.y);
    }

    //debug
    //for (auto& pos : this->possibleMoves) //debug
    //{
    //    cout << "position x: " << pos.x << endl << "position y: " << pos.y << endl << endl;
    //}
    return positions;
}