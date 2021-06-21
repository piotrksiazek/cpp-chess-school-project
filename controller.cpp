#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "controller.hpp"
#include "constants.hpp"
#include "square.hpp"
#include "board.hpp"
#include "utils.hpp"
#include "position.hpp"
#include "vector2.hpp"

using namespace std;
Controller::Controller(Board *board, int * squareX, int *squareY, SDL_Event *event)
{
    this->board = board;
    this->squareX = squareX;
    this->squareY = squareY;
    this->event = event;
    this->choosingPosition=false;

    this->currentPlayerColor = 'w';
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

bool Controller::isEnemy(Position otherPosition)
{
    if(this->board->board[otherPosition.y][otherPosition.x].piece != (Piece*)nullptr)
        return this->selectedPiece->color != this->board->board[otherPosition.y][otherPosition.x].piece->color; //if colors are not equal, other piece is an enemy
    return false;
}



vector<Position> Controller :: controllerGetPossibleMoves()
//returns vector of all possible moves for selected piece
{
    Piece* piece;
    piece = this->GetPieceOnMouseOver();
    vector<Position> positions;
    if(piece != nullptr && piece->color == this->currentPlayerColor)
    {
        this->selectedPiece = piece;
        positions = selectedPiece->getPossibleMoves();
        this->choosingPosition = true;
        filterOutObstacles(this->selectedPiece->position, positions);
        filterPawnMovements(positions);
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

void Controller::filterPawnMovements(vector<Position>& positions)
{
    if ((this->selectedPiece->name.compare("b_pawn") == 0 || this->selectedPiece->name.compare("w_pawn") == 0))
    {
        for (auto& pos : positions)
        {
            Piece* piece = this->board->board[pos.y][pos.x].piece;
            if ( (piece == (Piece*)nullptr && pos.x != this->selectedPiece->position.x ) || 
                (piece != (Piece*)nullptr && pos.x == this->selectedPiece->position.x))
                positions.erase(std::remove(positions.begin(), positions.end(), pos), positions.end());
        }
    }
}

void Controller::filterOutObstacles(Position currentPosition, vector<Position> &positions)
{
    Position directions[] = { vector2.up,
                             vector2.down,
                             vector2.left,
                             vector2.right,
                             vector2.upRight,
                             vector2.upLeft,
                             vector2.downRight,
                             vector2.downleft };

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Position currentSquarePosition = { currentPosition.x + j * directions[i].x, currentPosition.y + j * directions[i].y };
            //if ((currentSquarePosition.x < 8 && (currentSquarePosition.x >= 0 && (currentSquarePosition.y < 8 && (currentSquarePosition.y >= 0 && ((currentSquarePosition.x != currentPosition.x || (currentSquarePosition.y != currentPosition.y))))))))
            if(isPositionValid(currentSquarePosition, currentPosition))
            {
                if (!this->board->board[currentSquarePosition.y][currentSquarePosition.x].isFree)
                {
                    for (int k = j+1; k < 8; k++)
                    {
                        currentSquarePosition = { currentPosition.x + k * directions[i].x, currentPosition.y + k * directions[i].y };
                        if (isPositionValid(currentSquarePosition, currentPosition))
                            //if(this->board->board[currentSquarePosition.y][currentSquarePosition.x].piece->color != this->board->board[currentPosition.y][currentPosition.x].piece->color)
                                positions.erase(std::remove(positions.begin(), positions.end(), currentSquarePosition), positions.end());
                    }
                }
            }
        }
    }

    for (auto& pos : positions) //filter out squares with pieces of the same color
    {
        if(this->board->board[pos.y][pos.x].piece != (Piece*)nullptr)
            if (this->board->board[currentPosition.y][currentPosition.x].piece != (Piece*)nullptr &&
                this->board->board[pos.y][pos.x].piece->color == this->board->board[currentPosition.y][currentPosition.x].piece->color)

                positions.erase(std::remove(positions.begin(), positions.end(), pos), positions.end());
    }
}

void Controller::changeCurrentPlayerColor()
{
    if (this->currentPlayerColor == 'w')
        this->currentPlayerColor = 'b';
    else if (this->currentPlayerColor == 'b')
        this->currentPlayerColor = 'w';
}