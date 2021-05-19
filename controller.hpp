#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "board.hpp"

#ifndef CONTROLLER_H
#define CONTROLLER_H
class Controller
{
    public:
        Controller(Board *board);
    private:
        Board *board; //pointer to board object
};

#endif