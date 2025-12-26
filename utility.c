#include "utility.h"

// Metodo per la creazione di un puntatore SDL_Window
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

// Metodo per la creazione di un puntatore SDL_Renderer
SDL_Renderer* createRenderer(SDL_Window* window)
{
    SDL_Renderer* renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    return renderer;
}

// Metodo per randerizzare un singolo punto -> Rect a schermo
// Colorore del pixel in base al "type" ed al numero di iterazioni "iter"
// a : nero
// p : bianco
// r : rosso
void drawPoint(SDL_Renderer* renderer, Point* point, int x, int y)
{
    // Set Render Color
    if (point->type == 'a') {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    } 
    else if (point->type == 'p') {
        if (point->iter == 0) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        } else {
            // Effetto magma
            int r = (point->iter * 8);
            if (r > 255) r = 255;

            int g = (point->iter > 15) ? (point->iter - 15) * 5 : 0;
            if (g > 255) g = 255;

            int b = (point->iter > 40) ? (point->iter - 40) * 2 : 0;
            if (b > 255) b = 255;

            SDL_SetRenderDrawColor(renderer, r, g, b, 255);
        }
    } 
    else if (point->type == 'r') {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    }

    SDL_Rect rect = (SDL_Rect) {x, y, RECT_SIZE, RECT_SIZE};
    SDL_RenderFillRect(renderer, &rect);
}

