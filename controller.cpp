#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "controller.hpp"
#include "constants.hpp"
#include "square.hpp"
#include "board.hpp"
#include "utils.hpp"
#include "position.hpp"

using namespace std;
Controller::Controller(Board *board, int * squareX, int *squareY)
{
    this->board = board;
    this->squareX = squareX;
    this->squareY = squareY;
    getPossibleMoves();
}

Piece * Controller :: GetPieceOnMouseOver()
{
    //checks which hovered rect contains specific piece and if exists returns pointer to piece, otherwise nullptr
    Piece * pointedPiece;
    for(auto& piece: this->board->pieces)
    {
        Position position;
        position = getCurrentHoveredRect(*this->board, this->squareX, this->squareY);
        if(position.x == piece->x && position.y == piece->y)
        {
            return piece;
        }
        
    }
    return (Piece *)(nullptr);
}

vector<Position> Controller :: getPossibleMoves()
//returns vector of all possible moves for selected piece
{
    Piece *piece;
    piece = this->GetPieceOnMouseOver();
    vector<Position> positions;
    if(piece != nullptr)
    {
        positions = piece->getPossibleMoves();
    }
    for(auto& pos : positions)
    {
        changeColor(*this->board, pos.x, pos.y);
    }
    return positions;
}