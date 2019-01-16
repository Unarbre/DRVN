#include "../../proto/supervisor.h"

int startGame(struct Univers *univers, struct Population *population, struct Land *land)
{
    char command[2];
    struct MU *currentMu;

    currentMu = population->startPopulation;
    printf("s pour commencer\n");
    fgets(command, 2, stdin);
    while (command[0] == 's' && univers->age < 3)
    {
        if(survival(univers, population, land, currentMu))
           printf("error Survival"); 
        univers->age += 1;
        printf("\nageUnivers : %d\n\n", univers->age);
    }
    return 0;
}

