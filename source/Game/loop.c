#include "../../proto/supervisor.h"
#include <stdio.h>


int startGame(struct Univers *univers, struct Population *population, struct Land *land)
{
    char command[2];
    struct MU *currentMu;
    currentMu = population->startPopulation;

    printf("s pour commencer\n");
    fgets(command, 2, stdin);
    while(command[0] == 's' && univers->age < 100)
    {
        for(int i = 0; i < population->density; i++)
        {
            
        }
        univers->age += 1;
        
    }
    printf("test\n");
    return 0;
}