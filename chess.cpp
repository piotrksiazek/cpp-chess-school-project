#include <iostream>
#include "initialization.hpp"
#include "constants.hpp"
using namespace std;

int main()
{
    initSDL();
    SDL_Window* window = createWindow(WIDTH, HEIGHT, "chess");
}