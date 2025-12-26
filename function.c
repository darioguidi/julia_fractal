#include "function.h"

// Creazione Piano
void drawGaussPlann(SDL_Renderer* renderer, Point* gauss_plan, int gauss_shape, int iter_max, float c_real, float c_img)
{
    for (int i = 0; i < WINDOW_WIDTH; i++){
        for (int j = 0; j < WINDOW_HEIGHT; j++){

            // Calcolo index
            int idx = (j * WINDOW_WIDTH) + i;
            if (idx >= gauss_shape) continue;

            gauss_plan[idx].real = (float)(i-GAUSS_CENTER_X) / WIND_ZOOM;
            gauss_plan[idx].img = (float)(GAUSS_CENTER_Y-j) / WIND_ZOOM;

            gauss_plan[idx].iter = calculateIter(&gauss_plan[idx], iter_max, c_real, c_img);

            if (j == GAUSS_CENTER_Y || i == GAUSS_CENTER_X){
                gauss_plan[idx].type = 'p';
            }else{
                gauss_plan[idx].type = 'p';
            }


        }  
    }
}

int calculateIter(Point* point, int iter_max, float c_real, float c_img)
{
    int iter = 0;
    float z_real = point->real;
    float z_img = point->img;

    // Controllo basato sul raggio di fuga (2^2 = 4) e limite massimo di iterazioni
    while ((z_real * z_real + z_img * z_img) <= 4.0f && iter < iter_max) {
        float next_real = (z_real * z_real) - (z_img * z_img) + c_real;
        float next_img = (2.0f * z_real * z_img) + c_img;

        z_real = next_real;
        z_img = next_img;

        iter++;
    }

    return iter;
}

void drawCirconference(SDL_Renderer* renderer, Point* gauss_plan, int gauss_shape, int radius)
{
    for (int i = 0; i < WINDOW_WIDTH; i++){
        for (int j = 0; j < WINDOW_HEIGHT; j++){

            // Calcolo index
            int idx = (j * WINDOW_WIDTH) + i;
            if (idx >= gauss_shape) continue;

            // Spessore circonferenza 0.1
            float theta = 0.01;

            float distance = pow(gauss_plan[idx].real, 2)+ pow(gauss_plan[idx].img, 2);

            if ((distance <= pow(radius+theta, 2)) && (distance >= pow(radius-theta, 2))){
                gauss_plan[idx].type = 'a';
            }
        }
    }

}

    Point* calculateComplexValues(float mouse_x, float mouse_y, float c_real, float c_img, int iter_max)
    {
        // Calcolo dei valori complessi, dati dalla iterazione della funzione del Insieme di Mandelbrot
        float z_real = (mouse_x - GAUSS_CENTER_X) / WIND_ZOOM;
        float z_img = (GAUSS_CENTER_Y - mouse_y) / WIND_ZOOM;

        Point* head = malloc(sizeof(Point));
        if (head == NULL) return NULL;

        head->real = z_real;
        head->img = z_img;
        head->nextComplex = NULL;

        // Putatore di appoggio
        Point* track = head;

        for (int i=0; i < iter_max; ++i) {

            // Funzione di iterazione -> z = z^2 + c
            // z^2 
            // nex_real = pow(a, 2)-pow(b,2)
            // new_img = 2ab
            float new_real = pow(track->real, 2) - pow(track->img, 2) + c_real;
            float new_img = (2 * track->real * track->img) + c_img;
            
            // Creo un punto a parte per i nuovi valori calcolati dalla iterazione
            Point* nextComplexValue = malloc(sizeof(Point));
            if (nextComplexValue == NULL) break;

            nextComplexValue->real = new_real;
            nextComplexValue->img = new_img;
            nextComplexValue->nextComplex = NULL;

            // Link nuovo punto
            track->nextComplex = nextComplexValue;
            // Aggiorno puntatore di appoggio
            track = nextComplexValue;
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
        // Puntatore di appoggio per scorrere la lista
        Point* current = head;

        // Color Rosso
        SDL_SetRenderDrawColor(renderer,255,0,0,255);

        while(current != NULL){
            int dx = (int)(current->real * WIND_ZOOM) + GAUSS_CENTER_X;
            int dy = (int)(GAUSS_CENTER_Y - (current->img * WIND_ZOOM));

            SDL_Rect rect = (SDL_Rect) {dx-1, dy-1, 4, 4};
            SDL_RenderDrawRect(renderer, &rect);

            current = current->nextComplex;
        }

    }





