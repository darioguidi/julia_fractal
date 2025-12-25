#include "function.h"


void drawGaussPlann(SDL_Renderer* renderer, Point* gauss_plan, int gauss_shape)
{
    // Debug
    // printf("Len di Gauss Plan: %d", gauss_shape);

    // Origine degli assi
    int gauss_center_x = (int) WINDOW_WIDTH/2;
    int gauss_center_y = (int) WINDOW_HEIGHT/2;

    // Creazione Piano 
    for (int i = 0; i < WINDOW_WIDTH; i++){
        for (int j = 0; j < WINDOW_HEIGHT; j++){

            // Calcolo index
            int idx = (j * WINDOW_WIDTH) + i;
            if (idx >= gauss_shape) continue;

            gauss_plan[idx].x = (i-gauss_center_x);
            gauss_plan[idx].y = (gauss_center_y-j);

            // Ogni punto partirà con il valore iter impostato a 0
            gauss_plan[idx].iter = 0;

            if (j == gauss_center_y || i == gauss_center_x){
                gauss_plan[idx].type = 'a';
            }else{
                gauss_plan[idx].type = 'p';
            }

            // Disegno punto dell'asse 
            drawPoint(renderer, &gauss_plan[idx], i, j);
        }  
    }
}

void drawCirconference(SDL_Renderer* renderer, Point* gauss_plan, int gauss_shape)
{

    // Origine degli assi
    int gauss_center_x = (int) WINDOW_WIDTH/2;
    int gauss_center_y = (int) WINDOW_HEIGHT/2;

    for (int i = 0; i < WINDOW_WIDTH; i++){
        for (int j = 0; j < WINDOW_HEIGHT; j++){

            // Calcolo index
            int idx = (j * WINDOW_WIDTH) + i;
            if (idx >= gauss_shape) continue;

            // Raggio circonferenza [-1,1]
            int radius = 100;

            // Spessore circonferenza 0.1
            int theta = 1;

            int distance = pow(gauss_plan[idx].x, 2)+ pow(gauss_plan[idx].y, 2);

            if (distance <= )
        }
    }

}