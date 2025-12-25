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


SDL_Renderer* createRenderer(SDL_Window* window)
{
    SDL_Renderer* renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    return renderer;
}

void drawPoint(SDL_Renderer* renderer, Point* point, int x, int y)
{
    // Colorore del pizel in base al "type" ed al numero di iterazioni "iter"
    if (point->type=='a'){
        SDL_SetRenderDrawColor(renderer, 255,255,255,255);
    }else if (point->type=='p'){
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    }else if (point->type == 'r'){
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    }

    SDL_Rect rect = (SDL_Rect) {x, y, RECT_SIZE, RECT_SIZE};
    SDL_RenderFillRect(renderer, &rect);
}

