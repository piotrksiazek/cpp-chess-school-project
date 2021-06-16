#pragma once
typedef struct Position { 
    int x,y;
    bool operator == (Position a) {
        return a.x == x && a.y == y;
    }
} Position;