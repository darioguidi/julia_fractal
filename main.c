#include "function.h"

window_width = WINDOW_WIDTH;
window_height = WINDOW_HEIGHT;

// Main
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
    // running : variabile impostat su uno stato booleano "Attivo", permette l'apertura della finestra e del render. 
    // Lo stato a 0 "Inattivo" viene dichiarato nel momento della chiusura della finestra, interrompendone la visualizzazione
    // iter_max_gauss : Indica il numero di iterazioni da utilizzare in fase di creazione del frattale nel piano di gauss
    // iter_max : Indica il numero di iterazioni da svolgere per il calcolo dei risultati complessi dati dall'applicazione della funzione z = z^2 + c
    // gauss_shape : Indica la dimensione del piano di numeri complessi (gauss)
    // chooice : Indica lascleta del valore complesso individuato dall'utente per la scelta del frattae da generare
    int running = 1;
    int iter_max_gauss = 100;
    int iter_max = 100;
    int gauss_shape = WINDOW_WIDTH*WINDOW_HEIGHT;
    int chooice;
    
    // mouseX, mouseY : Coordinate del mouse sulla finestra
    float mouseX, mouseY, c_real, c_img;
    
    // Raggio circonferenza in valore matematico r = 1
    float radius = 1.0f;

    // Generazione piano complesso (Piano di Gauss)
    Point* gauss_plan = (Point*) malloc(sizeof(Point) * (gauss_shape));
    if (gauss_plan == NULL){
        printf("Errore nella attribuzione di memoria per il piano di gauss \n");
        return 0;
    }

    // Scelta del valore complesso da passare alla funzione per la generazione del frattale
    printf("Scegliere quale valore complesso utilizzare per la generazione del frattale di Julia \n");
    printf("1 -> c=−0.123+0.745i \n2 -> c=−0.4+0.6i \n3-> c = -0.8+0.156i \n4 -> c=0.0+1.0i \n 5 -> -0.8+0.156i");
    scanf("%d", &chooice);

    // Porzione di codice dedicata alla generazione di due valori float, generati in un intervallo di valori matematici pari a [-1,1]

    srand((unsigned int)time(NULL));

    float random_real = ((float)rand() / (float)RAND_MAX) * 2.0f - 1.0f;
    float random_img = ((float)rand() / (float)RAND_MAX) * 2.0f - 1.0f;

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
        case 5:
            c_real = 0.1348;
            c_img = -0.67;
            break;
        case 6 : 
            c_real = -0.521111;
            c_img = -0.45679;
            break;
        case 7 : 
            c_real = 0.521111;
            c_img = 0.45679;
            break;
        case 8 : 
            c_real = 0.12;
            c_img = 0.45;
            break;
        case 9 : 
            c_real = 0.29462;
            c_img = 0.9537;
            break;
        case 10 : 
            c_real = random_real;
            c_img = random_img;
            break;            
        default: 
            c_real = -0.8; 
            c_img = 0.156; 
            break;
    }

    // Creare lo spazio di Gauss
    drawGaussPlann(renderer, gauss_plan, gauss_shape, iter_max_gauss, c_real, c_img);

    // Metodo per il disegno della circonferenza unitaria
    // drawCirconference(renderer, gauss_plan, gauss_shape, radius);

    // Variabili gestione eventi finestra
    // isDragging : Stabilisce se si sta effettuando un evento di dragging con il mouse, se lo stato è "Attivo"
    // allora viene liberato l'array dinamico e vengono ricalcolati i punti della iterazione
    int isDragging = 0;

    // Testa dell'array dinamico per il calcolo dei risultati dati dalla iterazione della funzione z = z^2 + c
    Point* head = NULL;

    // Creazione oggetto SDL_Event per gestione della finestra
    SDL_Event event;

    // Finestra per la visualizzazione della finestra, render, gestione eventi
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

                    
                    window_width = new_w; 
                    window_height = new_h;

                    free(gauss_plan);
                    gauss_shape = new_w * new_h;
                    gauss_plan = (Point*) malloc(sizeof(Point) * gauss_shape);

                    drawGaussPlann(renderer, gauss_plan, gauss_shape, iter_max_gauss, c_real,);
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

        // Gestione evento dragging mouse per calcolo valori complessi della iterazione e relativo render
        if (isDragging){
            if (head != NULL){
                freeComplexList(head);
                head = NULL;
            }

            head = calculateComplexValues(mouseX, mouseY, c_real, c_img, iter_max);
        }
        if (head != NULL) {
            // Render Array Dinamico
            drawComplexvalues(renderer, head);
        }

        // Render video del risultato
        SDL_RenderPresent(renderer);
    }

    free(gauss_plan);
    free(head);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}
