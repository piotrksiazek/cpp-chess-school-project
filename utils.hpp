#include "board.hpp"

#ifndef UTILS_H
#define UTILS_H
typedef struct Position { 
    int x,y; 
} Position;
Position getCurrentHoveredRect(Board &board, int *squareX, int *squareY);
void changeColor(Board &board, int squareX, int squareY);
#endif