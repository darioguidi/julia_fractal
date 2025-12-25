#ifndef UTILITY_H
#define UTILITY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <SDL2/SDL.h>

// Define
#define WINDOW_WIDTH 800 // [-8, 8]
#define WINDOW_HEIGHT 800 //[-8, 8]
#define RECT_SIZE 2

// Struct
// type : "a" -> asse
// type : "p" -> valori persi
typedef struct Point {
    float real;
    float img;
    int iter;
    char type;
} Point;

typedef struct ComplexNumber {
    float real;
    float img;
} ComplexNumber;

//  Methods
SDL_Window* createWindow();
SDL_Renderer* createRenderer(SDL_Window* window);
void drawPoint(SDL_Renderer* renderer, Point* point, int x, int y);


#endif