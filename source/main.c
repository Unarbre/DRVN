#include "../proto/supervisor.h"

int main(int argc, char **argv)
{
    int wait = 1;

    graphGenerateMenu();
    while(wait != 0)
    {
        // SDL_Delay(1000);
        SDL_PumpEvents();
        {
            const Uint8* pKeyStates = SDL_GetKeyboardState(NULL);
            // quit
            if ( pKeyStates[SDL_SCANCODE_ESCAPE] )
            {
                wait = 0;
            }
            // start simulation
            if(pKeyStates[SDL_SCANCODE_RETURN])
            {
                wait = simulation();
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
    // SDL_Quit();
    return wait;
}

int simulation()
{
    srand(time(NULL));

    struct Univers *univers = malloc(sizeof(struct Univers));
    int idMu = 1;
    struct Population *population;
    struct Land land;
    // Size is modulable
    int size = 15;

    // GENERATION OF UNIVERS    
    initiateLand(&land, size);
    population = initiatePopulation(&land, 11, &idMu, size);
    initiateUnivers(univers, idMu, population, &land);
    graphGenerateWorld(univers);

    printf("play\n");
    startGame(univers);
    
    freeUnivers(univers);

    return 42;
}

