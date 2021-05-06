#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "initialization.hpp"
#include "constants.hpp"
#include "board.hpp"
using namespace std;

bool isExitGame(SDL_Event *event)
{
    if (event->type == SDL_QUIT || (event->type == SDL_WINDOWEVENT && event->window.event == SDL_WINDOWEVENT_CLOSE)) 
        return true;
    return false;
}

int main()
{
    bool exitGame = false;
    initSDL();
    SDL_Event event;
    SDL_Window* window = createWindow(WIDTH, HEIGHT, "chess");
    SDL_Renderer* renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderClear( renderer );
    Board board;
    while(!exitGame)
    {
        while (SDL_PollEvent(&event)) 
        {
            exitGame = isExitGame(&event);
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}