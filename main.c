#include "utility.h"

// Mian del progetto
int main() 
{
    // Generazione SDL_Window
    SDL_Window* window = createWindow();

    if (window == NULL){
        printf("Errore nella creazione della SDL_Window \n");
        return 0;
    }

    // Generazione SDL_Renderer
    SDL_Renderer* renderer = createRenderer();

    float c_real, c_img;

    printf("Scegliere quale valore compleso utilizzare per la generazione del frattale di Julia \n");
    printf("");


    scanf("%f %f", &c_real, &c_img);

    printf("%.2f %.2f", c_real, c_img);

    SDL_DestroyWindow(window);

    return 0;
}
