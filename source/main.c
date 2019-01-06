#include "../proto/supervisor.h"

// test
int main(int argc, char **argv)
{
    srand(time(NULL));
    int idMu = 0;
    int population = 10;
    int size = 50;
    struct Land land;
    struct MU *Mus = malloc(sizeof(struct MU) * 10);
    initiateLand(&land, size);
    initiatePopulation(Mus, 10, &idMu, land.size, 10);
    struct Univers univers;
    initiateUnivers(&univers, 1, idMu, population, Mus, &land);

    univers.mus = procreate(&(univers.population), &(univers.lastChildId), univers.mus, univers.age);
    printMu(&(univers.mus[univers.population - 1]));
    printTile(land.tiles[30][30]);
    freeUnivers(&univers);
    printf("outiout!");

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