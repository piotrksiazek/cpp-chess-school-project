#include <iostream>
#include <SDL2/SDL.h>
#include "constants.hpp"
#include "square.hpp"
#include "board.hpp"
#include "utils.hpp"

//ustawia wartości wskazywane przez squareX i squareY na odpowiendnie liczby będące indexami tablicy board
Position getCurrentHoveredRect(Board &board, int *squareX, int *squareY)
{
    int xMouse, yMouse;
    int rectSize = WIDTH / 8;
    SDL_GetMouseState(&xMouse,&yMouse);
    *squareX=xMouse/rectSize;
    *squareY=yMouse/rectSize;
    Position position = {xMouse/rectSize, yMouse/rectSize };
    return position;
    // board.board[squareY][squareX].setColor(BLACK);
}

void changeColor(Board &board, int squareX, int squareY)
{
    board.board[squareY][squareX].setColor(BLACK);
}