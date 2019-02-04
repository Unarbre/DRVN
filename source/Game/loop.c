#include "../../proto/supervisor.h"

// loop for the game
int startGame(struct Univers *univers)
{
    struct MU *currentMu;
    int loop = 1;

    currentMu = univers->population->startPopulation;

    for (int i = 0; i < univers->population->density; i++)
    {
        printf("\n idMu : %d  ", currentMu->idMu);
        printf(" position %d  ", currentMu->position[0]);
        printf(" %d ", currentMu->position[1]);
        currentMu = currentMu->next;
    }

    while (loop && (univers->age < 15 && univers->population->startPopulation != NULL))
    {
        printf("\nloop : %d \n\n", loop);
        printf("pap %d\n", univers->population->startPopulation->idMu);
        //move Mu
        movement(univers);
        reproduction(univers);
        

        // change status and lifePoints of each Mu
        survival(univers);
        puts("chien");
        //kill Mu who need to be killed
        death(univers);
        univers->age += 1;
        printf("\nageUnivers : %d\n\n", univers->age);

        graphFillWorld(univers);
        // loop = sdlEvent(univers);
         SDL_Delay(1000);
    }
    return 0;
}