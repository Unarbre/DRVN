#include "../../proto/supervisor.h"

int survival(struct Univers *univers)
{
    struct MU *currentMu = univers->population->startPopulation;

    while(currentMu != NULL)
    {
        // add or remove pv depending on current status
        changePv(univers, &currentMu);
        // change status according capacity and pressures
        currentMu->status = testStatus(univers->land, &currentMu);
        currentMu = currentMu->next;
    }
    return 1;
}

//status 0 -> -2pv          status 1 or 2-> -1pv
int changePv(struct Univers *univers, struct MU ** PcurrentMu)
{
    if(PcurrentMu[0]->status == 0)
        PcurrentMu[0]->lifePoints -= 2;
    else if(PcurrentMu[0]->status == 1 || PcurrentMu[0]->status == 2)
        PcurrentMu[0]->lifePoints -= 1;
    return 1;
}

// change status
int testStatus(struct Land *land, struct MU ** PcurrentMu)
{
    int average = 1;
    int x = PcurrentMu[0]->position[0];
    int y = PcurrentMu[0]->position[1];
    int *capacityMu = PcurrentMu[0]->capacity;

    average = resistance(land, capacityMu, x, y);
    if(average < -25 || average == 4242)
        return 0;
    if(average < 25)
        return 1;
    return 2;
}

// calculate average resistance of the Mu
int resistance(struct Land *land, int *capacityMu, int x, int y)
{
    int average, resistance;
    average = 0;
    for(int i = 4; i <12; i++)
    {
        // calculate resistance for each pressure
        resistance = capacityMu[i] - land->tiles[x][y].pressures[i-4];
        if( resistance < -50)
            return 4242;
        average += resistance;
    }
    average /= 8;
    return average;
}