#ifndef UTILITY_H
#define UTILITY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <SDL2/SDL.h>

// Define
#define WINDOW_WIDTH 400 // [-4, 4]
#define WINDOW_HEIGHT 400 //[-4, 4]
#define RECT_SIZE 2

// Struct
// type : "a" -> asse
// type : "p" -> valori persi
typedef struct Point {
    float x;
    float y;
    int iter;
    char type;
} Point;

//  Methods
SDL_Window* createWindow();
SDL_Renderer* createRenderer(SDL_Window* window);
void drawPoint(SDL_Renderer* renderer, Point* point, int x, int y);

#endif