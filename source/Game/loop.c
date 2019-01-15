#include "../../proto/supervisor.h"

// int resistance(struct Univers *univers, struct MU * mu);

int startGame(struct Univers *univers, struct Population *population, struct Land *land)
{
    char command[2];
    struct MU *currentMu;

    printf("s pour commencer\n");
    fgets(command, 2, stdin);
    while (command[0] == 's' && univers->age < 2)
    {
        currentMu = univers->population->startPopulation;
        for (int i = 0; i < population->density && currentMu->next != NULL; i++)
        {
            if(testStatus(univers, population, land, &currentMu, i))
                printf("error");
        }
        univers->age += 1;
        printf("\nageUnivers : %d\n\n", univers->age);
    }
    return 0;
}

int testStatus(struct Univers *univers, struct Population *population, struct Land *land, struct MU ** PcurrentMu, int idMu)
{
    int newStatus = 1;

    printf("\n idMu : %d  ", PcurrentMu[0]->idMu);
    printf(" status : %d  ", PcurrentMu[0]->status);
    newStatus = resistance(univers, PcurrentMu[0]);
        // printf("\n");
        // printf("   Capacity %d", PcurrentMu[0]->capacity[i]);
    PcurrentMu[0]->status = newStatus;
    *PcurrentMu = PcurrentMu[0]->next;
    return 0;
}

int resistance(struct Univers *univers, struct MU * mu)
{
    int average, resistance;
    average = 0;
    for(int i = 4; i <12; i++)
    {
        resistance = mu->capacity[i] - univers->land->tiles[mu->position[0]][mu->position[1]].pressures[i-4];
        if( resistance < -50)
            return 0;
    }
    average /= 8;
    printf("average : %d\n", average);
    if(average < -25)
        return 0;
    if(average < 25)
        return 1;
    return 2;
}