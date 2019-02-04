#include "../proto/supervisor.h"

// papillon
int main(int argc, char **argv)
{
    srand(time(NULL));
    int idMu = 1;

//Initialisation 

    // Size is modulable
    int size = 15;

    // GENERATION OF UNIVERS
    struct Land land;
    // printf("%d\n", population->startPopulation->idMu);
    initiateLand(&land, size);
    struct Population *population = initiatePopulation(&land, 11, &idMu, size);

    struct Univers *univers = malloc(sizeof(struct Univers));
    initiateUnivers(univers, 1, idMu, population, &land);

    graphGenerateWorld(univers);

//Menu

    if(menu(univers) == 0)
        return 0;


//Game

    // if (!startGame(univers))
    // {
    //     // printf("\n%d\n", univers->age);

    //     // printf("%d\n", univers->age);

    //     // printMu(population->startPopulation);
    //     // printTile(land.tiles[15][15]);
    //     freeUnivers(univers);

    //     // printf("outiout!");
    //     return 0;
    // }
    // return 1;
}

int menu(struct Univers *univers)
{
    int wait = 1;

    
    while(wait == 1)
    {
        // SDL_Delay(1000);
        // wait = sdlMenu();
        SDL_PumpEvents();
        {
            const Uint8* pKeyStates = SDL_GetKeyboardState(NULL);
            if ( pKeyStates[SDL_SCANCODE_ESCAPE] )
            {
                wait = 0;
            }
            if(pKeyStates[SDL_SCANCODE_RETURN])
            {
                printf("play\n");
                startGame(univers);
            }
        }
        fprintf(stdout,"\n");
                // Souris
                {
                    int x=0;
                    int y=0;
                    // Uint32 boutons = SDL_GetMouseState(&x,&y);

                    // fprintf(stdout, "Position de la souris : %d;%d\n",x,y);
                    // fprintf(stdout, "Bouton de la souris : %d\n",boutons);

                    SDL_GetRelativeMouseState(&x,&y);
                    // fprintf(stdout, "Déplacement de la souris : %d;%d\n",x,y);
                }
                fprintf(stdout,"\n");
    }
    freeUnivers(univers);
    return wait;
}