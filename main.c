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
    int iter_max = 10;
    int gauss_shape = WINDOW_WIDTH*WINDOW_HEIGHT;
    int chooice;
    
    float mouseX, mouseY, c_real, c_img;
    float radius = 100.0f;

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
            c_real = 1;
            c_img = 1;
            break;
    }

    // Creare lo spazio di Gauss
    drawGaussPlann(renderer, gauss_plan, gauss_shape);
    drawCirconference(renderer, gauss_plan, gauss_shape, radius);

    Point* head = NULL;
    int isDragging = 0;

    // Creazione oggetto SDL_Event per gestione della finestra
    SDL_Event event;
    
    while(running){

        // Gestione eventi
        while(SDL_PollEvent(&event)){

            // Evento chiusura finestra interruzione ciclo
            if(event.type == SDL_QUIT){
                running = 0;
            }

            // Quando premo il tasto del mouse
            if(event.type == SDL_MOUSEBUTTONDOWN){
                if(event.button.button == SDL_BUTTON_LEFT){
                    isDragging = 1;

                    mouseX = event.button.x;
                    mouseY = event.button.y;
                }
            }

            // Quando rilascio il tasto del mouse
            if(event.type == SDL_MOUSEBUTTONUP){
                if(event.button.button == SDL_BUTTON_LEFT){
                    isDragging = 0;
                }
            }

            // Movimento del mouse: aggiorna solo se sto trascinando
            if(event.type == SDL_MOUSEMOTION){
                if(isDragging){
                    mouseX = event.motion.x;
                    mouseY = event.motion.y;
                }
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

        // 2. Gestione della traiettoria dinamica
        if (isDragging) {
            // Libera la memoria della traiettoria precedente
            if (head != NULL) {
                freeComplexList(head);
            }
            
            // Calcola la nuova traiettoria e assegna la nuova testa
            head = calculateComplexValues(mouseX, mouseY, c_real, c_img, iter_max);
        }

        // 3. Disegna la traiettoria se esiste
        if (head != NULL) {
            drawComplexvalues(renderer, head);
        }

        SDL_RenderPresent(renderer);
    }

    free(gauss_plan);
    free(head);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}
