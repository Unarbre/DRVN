#include "../../proto/supervisor.h"

// deltete mu, free positions, clean land
int death(struct Univers *univers)
{
    struct MU *currentMu = univers->population->startPopulation;

    while (currentMu != NULL)
    {
        if (currentMu->lifePoints <= 0)
        {
            univers->land->tiles[currentMu->position[0]][currentMu->position[1]].Mu = NULL;
            removeMu(univers, currentMu);
            univers->population->density--;
        }
        currentMu = currentMu->next;
    }
    return 0;
}

int removeMu(struct Univers *univers, struct MU *currentMu)
{
    struct MU *startPopulation = univers->population->startPopulation;
    struct MU *population = startPopulation;

    if (currentMu->idMu < 0)
        return -1;
    if (currentMu == startPopulation)
        return removeFirst(univers);
    while (population->next != currentMu)
    {
        population = population->next;
    }
    population->next = currentMu->next;
    toPosterity(currentMu, univers);
    freeMu(currentMu);

    return 0;
}

int removeFirst(struct Univers *univers)
{
    struct MU *tmp;
    struct MU *startPopulation = univers->population->startPopulation;

    if (startPopulation == NULL)
        return -1;
    tmp = startPopulation->next;
    toPosterity(startPopulation, univers);

    freeMu(startPopulation);

    univers->population->startPopulation = tmp;

    return 0;
}

void genocide(struct Univers *univers)
{
    struct MU *startPopulation = univers->population->startPopulation;
    while (startPopulation != NULL)
    {
        removeMu(univers, startPopulation);
        startPopulation = startPopulation->next;
    }
}