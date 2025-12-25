#include "function.h"


void drawGaussPlann(SDL_Renderer* renderer, Point* gauss_plan, int gauss_shape)
{
    // Debug
    // printf("Len di Gauss Plan: %d", gauss_shape);


    // float zoom = 200.0f;

    // Creazione Piano 
    for (int i = 0; i < WINDOW_WIDTH; i++){
        for (int j = 0; j < WINDOW_HEIGHT; j++){

            // Calcolo index
            int idx = (j * WINDOW_WIDTH) + i;
            if (idx >= gauss_shape) continue;

            gauss_plan[idx].real = (i-GAUSS_CENTER_X);
            gauss_plan[idx].img = (GAUSS_CENTER_Y-j);

            // Ogni punto partirà con il valore iter impostato a 0
            gauss_plan[idx].iter = 0;

            if (j == GAUSS_CENTER_Y || i == GAUSS_CENTER_X){
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

Point* calculateComplexValues(float mouse_x, float mouse_y, float c_real, float c_img, int iter_max)
{
    float z_real = (mouse_x - GAUSS_CENTER_X);
    float z_img = (GAUSS_CENTER_Y - mouse_y);

    Point* head = malloc(sizeof(Point));
    if (head == NULL) return NULL;

    head->real = z_real;
    head->img = z_img;
    head->nextComplex = NULL;

    Point* current = head;

    for (int i = 0; i < iter_max; i++) {
        float real = current->real;
        float img = current->img;

        if ((real * real + img * img) < 4.0f) {
            
            float next_r = (real * real - img * img) + c_real;
            float next_it = (2 * real * img) + c_img;

            Point* nextNode = malloc(sizeof(Point));
            nextNode->real = next_r;
            nextNode->img = next_it;
            nextNode->nextComplex = NULL;

            current->nextComplex = nextNode;
            current = nextNode;
        } else {
            break; 
        }
    }

    return head;
}

void freeComplexList(Point* head) {
    Point* current = head;
    while (current != NULL) {
        Point* next = current->nextComplex;
        free(current);
        current = next;
    }
}

void drawComplexvalues(SDL_Renderer* renderer, Point* head)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    Point* current = head;

    while (current != NULL) {
        int screen_x = (int)current->real + GAUSS_CENTER_X;
        int screen_y = (int)GAUSS_CENTER_Y - (int)current->img;

        SDL_Rect rect = {screen_x - 1, screen_y - 1, 3, 3};
        SDL_RenderFillRect(renderer, &rect);

        current = current->nextComplex;
    }
}

