#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "controller.hpp"

using namespace std;
Controller::Controller(Board *board)
{
    this->board = board;
    for(auto& piece: this->board->pieces)
    {
        piece->print();
    }
}
