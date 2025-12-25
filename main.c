#include "function.h"

// Main del progetto
int main() 
{
    // Inizializzazione SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0){
        printf("Errore nella inizializzazione dei sotto insiemi SDL \n");
        return 0;
    }

    // Generazione SDL_Window
    SDL_Window* window = createWindow();
    if (window == NULL){
        printf("Errore nella creazione della SDL_Window \n");
        return 0;
    }

    // Generazione SDL_Renderer
    SDL_Renderer* renderer = createRenderer(window);
    if (renderer == NULL){
        printf("Errore nella creazione del oggetto SDL_Renderer \n");
        return 0;
    }

    int running = 1;
    int gauss_shape = WINDOW_WIDTH*WINDOW_HEIGHT;
    int chooice;

    Point* gauss_plan = (Point*) malloc(sizeof(Point) * (gauss_shape));
    if (gauss_plan == NULL){
        printf("Errore nella attribuzione di memoria per il piano di gauss \n");
        return 0;
    }

    printf("Scegliere quale valore complesso utilizzare per la generazione del frattale di Julia \n");
    printf("1 -> c=1+i1 \n2 -> c=−0.123+0.745i \n3 -> c=−0.4+0.6i\n");

    scanf("%d", &chooice);

    // Creazione oggetto SDL_Event per gestione della finestra
    SDL_Event event;
    
    while(running){

        // Gestione eventi
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                running = 0;
            }
        }

        // Render del contenuto
        SDL_SetRenderDrawColor(0,0,0,0,SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        // Creare lo spazio di Gauss
        drawGaussPlann(renderer, gauss_plan, gauss_shape);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}
