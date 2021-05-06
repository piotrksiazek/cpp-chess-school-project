#include <iostream>
#include "initialization.hpp"
using namespace std;

int main()
{
    initSDL();
    SDL_Window* window = createWindow(500, 500, "chess");
}