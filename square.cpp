#include <iostream>
#include <SDL2/SDL.h>
#include "square.hpp"
#include "constants.hpp"
using namespace std;

Square::Square(){}

//Może trochę dziwnie to wygląda, bo addProps roby tyle, co mógłby zrobić konstruktor, ale chciałem aby plansza Square board[8][8]
//w klasie board została utworzona bezpośrednio w klasie, bez wyciągania tego np. do funkcji main.
void Square::addProps(int x, int y, int r, int g, int b, int a, SDL_Renderer* renderer)
{
    this->x = x;
    this->y = y;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
    this->renderer = renderer;
    this->rectangle = createRect(x, y);
    setColor(r,g,b,a);
}

SDL_Rect Square::createRect(int x, int y)
{
    SDL_Rect r;
    r.x = x * RECT_SIZE;
    r.y = y * RECT_SIZE;
    r.w = RECT_SIZE;
    r.h = RECT_SIZE;

    return r;
}

void Square::print()
{
    cout<<"x:  "<<this->x<<endl;
    cout<<"y:  "<<this->y<<endl;
    cout<<"r:  "<<this->r<<endl;
    cout<<"g:  "<<this->g<<endl;
    cout<<"b:  "<<this->b<<endl;
    cout<<"a:  "<<this->a<<endl<<endl;
}

void Square::setColor(int r, int g, int b, int a)
{
    SDL_Rect rectangle = this->rectangle;
    SDL_SetRenderDrawColor( this->renderer, r, g, b, a );
    SDL_RenderFillRect( this->renderer, &rectangle );
}