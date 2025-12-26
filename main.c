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
    int iter_max_gauss = 100;
    int iter_max = 100;
    int gauss_shape = WINDOW_WIDTH*WINDOW_HEIGHT;
    int chooice;
    
    float mouseX, mouseY, c_real, c_img;

    // Piano complesso (Piano di Gauss)
    Point* gauss_plan = (Point*) malloc(sizeof(Point) * (gauss_shape));
    if (gauss_plan == NULL){
        printf("Errore nella attribuzione di memoria per il piano di gauss \n");
        return 0;
    }

    // Scelta del valore complesso da passare alla funzione per la generazione del frattale
    printf("Scegliere quale valore complesso utilizzare per la generazione del frattale di Julia \n");
    printf("1 -> c=−0.123+0.745i \n2 -> c=−0.4+0.6i\n");
    scanf("%d", &chooice);

    // Assegnazioni dei valori del frattale di Julia da andare a generare
    switch(chooice){
        case 1 :
            c_real = -0.123;
            c_img = 0.745;
            break;
        case 2 : 
            c_real = -0.4;
            c_img = 0.6;
            break;
        case 3:
            c_real = -0.8;
            c_img = 0.156;
            break;
        case 4: 
            c_real = 0.0; 
            c_img = 1.0; 
            break;
        default: 
            c_real = -0.8; 
            c_img = 0.156; 
            break;
    }

    // Creare lo spazio di Gauss
    drawGaussPlann(renderer, gauss_plan, gauss_shape, iter_max_gauss, c_real, c_img);

    // Raggio circonferenza in valore matematico r = 1
    float radius = 1.0f;
    //drawCirconference(renderer, gauss_plan, gauss_shape, radius);

    // Variabili gestione eventi finestra
    int isDragging = 0;

    // Variabili gestione calcoli finestra
    Point* head = NULL;

    // Creazione oggetto SDL_Event per gestione della finestra
    SDL_Event event;

    while(running){

        // Gestione eventi
        while(SDL_PollEvent(&event)){

            // Evento chiusura finestra interruzione ciclo
            if(event.type == SDL_QUIT){
                running = 0;
            }
            
            /*
            if (event.type == SDL_WINDOWEVENT) {
                if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                    int new_w = event.window.data1;
                    int new_h = event.window.data2;

                    
                    // window_width = new_w; 
                    // window_height = new_h;

                    // 2. Libera e rialloca gauss_plan
                    free(gauss_plan);
                    gauss_shape = new_w * new_h;
                    gauss_plan = (Point*) malloc(sizeof(Point) * gauss_shape);

                    // 3. Ricalcola il piano e la circonferenza con le nuove dimensioni
                    drawGaussPlann(renderer, gauss_plan, gauss_shape);
                    drawCirconference(renderer, gauss_plan, gauss_shape, radius);
                }
            }
            */

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

        if (isDragging){
            if (head != NULL){
                freeComplexList(head);
                head = NULL;
            }

            head = calculateComplexValues(mouseX, mouseY, c_real, c_img, iter_max);
        }
        if (head != NULL) {
            drawComplexvalues(renderer, head);
        }

        SDL_RenderPresent(renderer);
    }

    free(gauss_plan);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}
