#include "../../proto/supervisor.h"

int survival(struct Univers *univers, struct Population *population, struct Land *land, struct MU *currentMu)
{
    currentMu = univers->population->startPopulation;
    for (int i = 0; i < population->density && currentMu->next != NULL; i++)
    {
        if(changePv(univers, population, land, &currentMu))
            printf("error changePv");
        if(testStatus(univers, population, land, &currentMu))
            printf("error testStatus");
        currentMu = currentMu->next;
    }
    return 0;
}

int changePv(struct Univers *univers, struct Population *population, struct Land *land, struct MU ** PcurrentMu)
{
    if(PcurrentMu[0]->status == 0)
        PcurrentMu[0]->lifePoints -= 2;
    printf("\n idMu : %d  ", PcurrentMu[0]->idMu);
    printf(" status : %d  ", PcurrentMu[0]->status);
    printf(" pv = %d", PcurrentMu[0]->lifePoints);
    return 0;
}

int testStatus(struct Univers *univers, struct Population *population, struct Land *land, struct MU ** PcurrentMu)
{
    int newStatus = 1;

    newStatus = resistance(univers, PcurrentMu[0]);
        // printf("\n");
        // printf("   Capacity %d", PcurrentMu[0]->capacity[i]);
    PcurrentMu[0]->status = newStatus;
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
        {
            printf(" résistance : %d", resistance);
            return 0;
        }
        average += resistance;
    }
    average /= 8;
    if(average < -25)
        return 0;
    if(average < 25)
        return 1;
    return 2;
}