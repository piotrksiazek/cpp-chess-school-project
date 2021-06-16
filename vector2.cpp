#include "vector2.hpp"

Vector2 vector2 = { {-1,0}, //left
                    {1,0},  //right
                    {0,-1}, //up
                    {0,1},  //down
                    {1, -1},//up right
                    {-1,-1},//up left
                    {1,1},  //down right
                    {-1,1} };//down left

bool isPositionValid(Position position, Position currentPosition)
{
    return (position.x < 8 && (position.x >= 0 && (position.y < 8 && (position.y >= 0 && ((position.x != currentPosition.x || (position.y != currentPosition.y)))))));
}