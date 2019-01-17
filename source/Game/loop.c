#include "../../proto/supervisor.h"

// loop for the game
int startGame(struct Univers *univers)
{
    char command[2];
    struct MU *currentMu;

    currentMu = univers->population->startPopulation;

    for(int i = 0;i < univers->population->density;i++)
    {
        printf("\n idMu : %d  ", currentMu->idMu);
        printf(" position %d  ", currentMu->position[0]);
        printf(" %d ", currentMu->position[1]);
        currentMu = currentMu->next;
    }
    printf("s pour commencer\n");
    fgets(command, 2, stdin);
    while (command[0] == 's' && univers->age < 3)
    {
        //move Mu
        if(movement(univers, currentMu))
           printf("error movement");

        // change status and lifePoints of each Mu
        if(survival(univers, currentMu))
           printf("error Survival"); 
        univers->age += 1;
        printf("\nageUnivers : %d\n\n", univers->age);
    }
    return 0;
}

