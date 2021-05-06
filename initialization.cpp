#include <SDL2/SDL.h>
#include <iostream>
#include <string>
using namespace std;

SDL_Window* createWindow(int width, int height, const char* title)
{
    /*Tworzę okno*/
    SDL_Window* win = SDL_CreateWindow(title,
                                        SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED,
                                        width, height, 0);
    
    /*Sprawdzam, czy okno zostało stworzone*/
    if(!win)
    {
        cout<<"Window creation error"<<endl;
        SDL_Quit();
        exit(1);
    }
    return win;
}

int initSDL()
{
    /*Inicjalizuję bibliotekę SDL*/
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        cout<<"SDL initialization error"<<endl;
        SDL_Quit();
        return 1;
    }
    cout<<"success"<<endl;
    return 0;
}