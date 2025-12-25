#ifndef FUNCTION_H
#define FUNCTION_H

#include "utility.h"

// Defines

// Methods
void drawGaussPlann(SDL_Renderer* renderer, Point* gauss_plan, int gauss_shape);
void drawCirconference(SDL_Renderer* renderer, Point* gauss_plan, int gauss_shape, int radius);
void drawComplexCircle(SDL_Renderer* renderer, float delta_real, float delta_img, ComplexNumber* c);


void drawItereactions();
void drawFractal();

#endif