#include "position.hpp"
#ifndef VECTOR2_H
#define VECTOR2_H
typedef struct Vector2 {
    Position left;
    Position right;
    Position up;
    Position down;
    Position upRight;
    Position upLeft;
    Position downRight;
    Position downleft;
} Vector2;
bool isPositionValid(Position position, Position currentPosition);
extern Vector2 vector2;

#endif