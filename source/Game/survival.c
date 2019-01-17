#include "../../proto/supervisor.h"

int survival(struct Univers *univers, struct MU *currentMu)
{
    currentMu = univers->population->startPopulation;
    for (int i = 0; i < univers->population->density && currentMu->next != NULL; i++)
    {
        // add or remove pv depending on current status
        if(changePv(univers, &currentMu))
            printf("error changePv");
        // change status according capacity and pressures
        currentMu->status = testStatus(univers, &currentMu);
        currentMu = currentMu->next;
    }
    return 0;
}

//status 0 -> -2pv          status 1 or 2-> -1pv
int changePv(struct Univers *univers, struct MU ** PcurrentMu)
{
    if(PcurrentMu[0]->status == 0)
        PcurrentMu[0]->lifePoints -= 2;
    else if(PcurrentMu[0]->status == 1 || PcurrentMu[0]->status == 2)
        PcurrentMu[0]->lifePoints -= 1;
    return 0;
}

// change status
int testStatus(struct Univers *univers, struct MU ** PcurrentMu)
{
    int average = 1;

    average = resistance(univers, PcurrentMu[0]);
    if(average < -25 || average == 4242)
        return 0;
    if(average < 25)
        return 1;
    return 2;
}

// calculate average resistance of the Mu
int resistance(struct Univers *univers, struct MU * mu)
{
    int average, resistance;
    average = 0;
    for(int i = 4; i <12; i++)
    {
        // calculate resistance for each pressure
        resistance = mu->capacity[i] - univers->land->tiles[mu->position[0]][mu->position[1]].pressures[i-4];
        if( resistance < -50)
            return 4242;
        average += resistance;
    }
    average /= 8;
    return average;
}