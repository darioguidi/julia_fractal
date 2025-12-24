#include "utility.h"

SDL_Window* createWindow()
{
    SDL_Window* window = SDL_CreateWindow(
        "Julia Fractal",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_RESIZABLE
    );

    return window;
}


SDL_Renderer* createRenderer()
{
    
}

void drawPoint(Point* point)
{


    return 0;
}