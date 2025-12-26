#ifndef FUNCTION_H
#define FUNCTION_H

#include "utility.h"

// Defines

// Methods
void drawGaussPlann(SDL_Renderer* renderer, Point* gauss_plan, int gauss_shape, int iter_max, float c_real, float c_img);
void drawCirconference(SDL_Renderer* renderer, Point* gauss_plan, int gauss_shape, int radius);
Point* calculateComplexValues(float mouse_x, float mouse_y, float c_real, float c_img, int iter_max);
void drawComplexvalues(SDL_Renderer* renderer, Point* head);
void freeComplexList(Point* head);
int calculateIter(Point* gauss_plan, int gauss_shape, float c_real, float c_img);

#endif