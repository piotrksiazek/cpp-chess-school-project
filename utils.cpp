#include <iostream>
#include <SDL2/SDL.h>
#include "constants.hpp"
#include "square.hpp"
#include "board.hpp"

//ustawia wartości wskazywane przez squareX i squareY na odpowiendnie liczby będące indexami tablicy board
void getCurrentHoveredRect(Board &board, int *squareX, int *squareY)
{
    int xMouse, yMouse;
    int rectSize = WIDTH / 8;
    SDL_GetMouseState(&xMouse,&yMouse);
    *squareX=xMouse/rectSize;
    *squareY=yMouse/rectSize;
    // board.board[squareY][squareX].setColor(BLACK);
}

void changeColor(Board &board, int squareX, int squareY)
{
    board.board[squareY][squareX].setColor(BLACK);
}