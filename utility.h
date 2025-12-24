#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <SDL2/SDL.h>

// Define
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

// Struct
typedef struct Point {
    float x;
    float y;
    float z;
    int iter;
    char type;
} Point;

//  Methods
SDL_Window* createWindow();
SDL_Renderer* createRenderer(SDL_Window* window);
void drawPoint(Point* point);