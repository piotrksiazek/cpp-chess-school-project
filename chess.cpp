#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "initialization.hpp"
#include "constants.hpp"
#include "board.hpp"
#include "utils.hpp"
#include "square.hpp"
#include "controller.hpp"
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
    initSDLImage();
    SDL_Event event;
    SDL_Window* window = createWindow(WIDTH, HEIGHT, "chess");
    SDL_Surface * surface = SDL_GetWindowSurface(window);
    SDL_Renderer* renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderClear( renderer );
    Board board(renderer);
    int squareX, squareY;
    board.populatePieces();
    Controller controller(&board, &squareX, &squareY); 
    while(!exitGame)
    {
        SDL_Delay(100);
        while (SDL_PollEvent(&event)) 
        {
            exitGame = isExitGame(&event);
        }
        getCurrentHoveredRect(board, &squareX, &squareY);
        controller.getPossibleMoves();
        // SDL_RenderCopy(renderer, image_texture, nullptr, &board.board[0][1].rectangle);
        board.renderPieces();
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}