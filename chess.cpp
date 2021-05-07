#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "initialization.hpp"
#include "constants.hpp"
#include "board.hpp"
#include "utils.hpp"
#include "square.hpp"
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

    SDL_Surface *image;
    image = IMG_Load("king.png");
    SDL_Texture* image_texture = SDL_CreateTextureFromSurface(renderer, image);
    if(!image) cout<<"no image"<<endl;

    while(!exitGame)
    {
        SDL_Delay(100);
        while (SDL_PollEvent(&event)) 
        {
            exitGame = isExitGame(&event);
        }
        getCurrentHoveredRect(board, &squareX, &squareY);
        SDL_RenderCopy(renderer, image_texture, nullptr, &board.board[0][1].rectangle);
        SDL_RenderPresent(renderer);
        board.renderPieces();
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}