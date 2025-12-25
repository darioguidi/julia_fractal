#include "function.h"


void drawGaussPlann(SDL_Renderer* renderer, Point* gauss_plan, int gauss_shape)
{
    // Debug
    // printf("Len di Gauss Plan: %d", gauss_shape);

    // Origine degli assi
    float gauss_center_x = WINDOW_WIDTH/2;
    float gauss_center_y = WINDOW_HEIGHT/2;
    // float zoom = 200.0f;

    // Creazione Piano 
    for (int i = 0; i < WINDOW_WIDTH; i++){
        for (int j = 0; j < WINDOW_HEIGHT; j++){

            // Calcolo index
            int idx = (j * WINDOW_WIDTH) + i;
            if (idx >= gauss_shape) continue;

            gauss_plan[idx].real = (i-gauss_center_x);
            gauss_plan[idx].img = (gauss_center_y-j);

            // Ogni punto partirà con il valore iter impostato a 0
            gauss_plan[idx].iter = 0;

            if (j == gauss_center_y || i == gauss_center_x){
                gauss_plan[idx].type = 'a';
            }else{
                gauss_plan[idx].type = 'p';
            }


        }  
    }
}

void drawCirconference(SDL_Renderer* renderer, Point* gauss_plan, int gauss_shape, int radius)
{
    for (int i = 0; i < WINDOW_WIDTH; i++){
        for (int j = 0; j < WINDOW_HEIGHT; j++){

            // Calcolo index
            int idx = (j * WINDOW_WIDTH) + i;
            if (idx >= gauss_shape) continue;

            // Spessore circonferenza 0.1
            float theta = 1;

            float distance = pow(gauss_plan[idx].real, 2)+ pow(gauss_plan[idx].img, 2);

            if ((distance <= pow(radius+theta, 2)) && (distance >= pow(radius-theta, 2))){
                gauss_plan[idx].type = 'a';
            }
        }
    }

}


void drawComplexCircle(SDL_Renderer* renderer, float delta_real, float delta_img, ComplexNumber* c)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); 
    
    int complex_radius = 10;
    for (int x = delta_real - complex_radius; x <= delta_real + complex_radius; x++) {
        for (int y = delta_img - complex_radius; y <= delta_img + complex_radius; y++) {
            
            // Distanza dal centro 
            float dx = x - delta_real; 
            float dy = y - delta_img;  
            
            // x^2 + y^2 <= r^2
            if ((dx * dx + dy * dy) <= (complex_radius * complex_radius)) {
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }
    }
}

