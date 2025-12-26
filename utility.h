#ifndef UTILITY_H
#define UTILITY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <SDL2/SDL.h>

// Define
#define MATH_RANGE 4.0f
#define WINDOW_WIDTH 600 // [-3, 3]
#define WINDOW_HEIGHT (WINDOW_WIDTH) // [-3, 3]
#define WIND_ZOOM (WINDOW_WIDTH / MATH_RANGE)
#define GAUSS_CENTER_X (WINDOW_WIDTH/2) // Origine degli assi (x)
#define GAUSS_CENTER_Y (WINDOW_HEIGHT/2) // Origine degli assi (y)
#define RECT_SIZE 1

// Struct
// type : "a" -> asse
// type : "p" -> valori persi
typedef struct Point {
    float real;
    float img;
    int iter;
    char type;
    struct Point* nextComplex;
} Point;


//  Methods
SDL_Window* createWindow();
SDL_Renderer* createRenderer(SDL_Window* window);
void drawPoint(SDL_Renderer* renderer, Point* point, int x, int y);


#endif