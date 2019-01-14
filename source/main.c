#include "../proto/supervisor.h"

// papillon
int main(int argc, char **argv)
{
    srand(time(NULL));
    int idMu = 0;

    // Size is modulable
    int size = 20;

    // GENERATION OF UNIVERS
    struct Land land;
    struct Population *population = initiatePopulation(10, &idMu, size);
    // printf("%d\n", population->startPopulation->idMu);
    initiateLand(&land, size);
    struct Univers *univers = malloc(sizeof(struct Univers));
    initiateUnivers(univers, 1, idMu, population, &land);
    
    if(!startGame(univers, population, &land))
    {
            // printf("%d\n", univers->age);



        // printMu(population->startPopulation);
        // printTile(land.tiles[15][15]);
        freeUnivers(univers);

        // printf("outiout!");

        // if (SDL_Init(SDL_INIT_VIDEO) != 0)
        // {
        //     fprintf(stdout, "Échec de l'initialisation de la SDL (%s)\n", SDL_GetError());
        //     return -1;
        // }

        // {
        //      //Création de la fenêtre
        //     SDL_Window *pWindow = NULL;
        //     pWindow = SDL_CreateWindow("Ma première application SDL2", SDL_WINDOWPOS_UNDEFINED,
        //                                SDL_WINDOWPOS_UNDEFINED,
        //                                640,
        //                                480,
        //                                SDL_WINDOW_FULLSCREEN_DESKTOP);

        //     if (pWindow)
        //     {
        //         SDL_Delay(3000);  //Attendre trois secondes, que l'utilisateur voit la fenêtre

        //         SDL_DestroyWindow(pWindow);
        //     }
        //     else
        //     {
        //         fprintf(stderr, "Erreur de création de la fenêtre: %s\n", SDL_GetError());
        //     }
        // }

        // SDL_Quit();
       return 0;
    }
    return 1;
}