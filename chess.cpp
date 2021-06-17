#include <iostream>
#include <SDL.h>
#undef main
#include <SDL_image.h>
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
    Controller controller(&board, &squareX, &squareY, &event); 
    board.initBoard();
    board.populatePieces();
    while(!exitGame)
    {
        SDL_Delay(100);
        board.drawBoard();
        while (SDL_PollEvent(&event)) 
        {
            //game logic
            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                controller.controllerGetPossibleMoves();
                if (controller.selectedPiece != (Piece*)nullptr && controller.selectedPiece->color == controller.currentPlayerColor) //we go further only if it's current players turn
                {
                    if (!controller.possibleMoves.empty()) //player can move only if vector possibleMoves is not empty
                    {
                        Position position = getCurrentHoveredRect(board, &squareX, &squareY);
                        if (controller.isChoosenRectInPossibleMoves(position))

                            if (controller.isEnemy(position))
                            {
                                board.killPiece(board.board[position.y][position.x].piece);
                                controller.board->movePieceToPosition(controller.selectedPiece, position);
                            }
                            else
                                controller.board->movePieceToPosition(controller.selectedPiece, position);
                    }
                }
                else
                    controller.selectedPiece = (Piece*)nullptr;
            }

            exitGame = isExitGame(&event);
        }
        getCurrentHoveredRect(board, &squareX, &squareY);
        // SDL_RenderCopy(renderer, image_texture, nullptr, &board.board[0][1].rectangle);
        board.renderPieces();
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}