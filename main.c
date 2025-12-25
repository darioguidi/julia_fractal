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

    // Variabili
    int running = 1;
    int gauss_shape = WINDOW_WIDTH*WINDOW_HEIGHT;
    int chooice;
    
    float mouseX, mouseY;
    float radius = 100.0f;

    
    ComplexNumber* c = malloc(sizeof(ComplexNumber));
    if (c == NULL) {
        printf("Errore nella creazione del numero complesso \n");
        return 0;
    }

    // Piano complesso (Piano di Gauss)
    Point* gauss_plan = (Point*) malloc(sizeof(Point) * (gauss_shape));
    if (gauss_plan == NULL){
        printf("Errore nella attribuzione di memoria per il piano di gauss \n");
        return 0;
    }

    // Scelta del valore complesso da passare alla funzione per la generazione del frattale
    printf("Scegliere quale valore complesso utilizzare per la generazione del frattale di Julia \n");
    printf("1 -> c=1+i1 \n2 -> c=−0.123+0.745i \n3 -> c=−0.4+0.6i\n");
    scanf("%d", &chooice);

    switch(chooice){
        case 1 :
            c->real = 1;
            c->img = 1;
            break;
    }

    // Creare lo spazio di Gauss
    drawGaussPlann(renderer, gauss_plan, gauss_shape);
    drawCirconference(renderer, gauss_plan, gauss_shape, radius);
    drawComplexCircle(renderer, 0, 0, c);

    // Creazione oggetto SDL_Event per gestione della finestra
    SDL_Event event;
    
    while(running){

        // Gestione eventi
        while(SDL_PollEvent(&event)){

            // Evento chiusura finestra interruzione ciclo
            if(event.type == SDL_QUIT){
                running = 0;
            }

            // Movimento del mouse
            if(event.type == SDL_MOUSEMOTION){
                mouseX = event.motion.x;
                mouseY = event.motion.y;
            }
        }

        // Render del contenuto
        SDL_SetRenderDrawColor(renderer, 0,0,0,255);
        SDL_RenderClear(renderer);

        for (int i = 0; i < WINDOW_WIDTH; i++){
            for (int j = 0; j < WINDOW_HEIGHT; j++){

                int idx = (j * WINDOW_WIDTH) + i;
                if (idx >= gauss_shape) continue;

                drawPoint(renderer, &gauss_plan[idx], i , j);
            }
        }

        // Aggiorno la posizione del cerchio al centro
        drawComplexCircle(renderer, mouseX, mouseY, c);

        SDL_RenderPresent(renderer);
    }

    free(gauss_plan);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}
