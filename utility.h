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
    char type;
} Point;

//  Methods
SDL_Window* SDL_CreateWindow();
SDL_Renderer* createRenderer();
void drawPoint(Point* point);