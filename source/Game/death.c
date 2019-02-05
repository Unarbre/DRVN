#include "../../proto/supervisor.h"

// deltete mu, free positions, clean land
int death(struct Univers *univers)
{
    struct MU *currentMu = univers->population->startPopulation;

    printf("startPopulation %d\n", currentMu->idMu);
    while (currentMu != NULL)
    {
        printf("\nidmu : %d lifepoints : %d ", currentMu->idMu, currentMu->lifePoints);
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

    printf(" indexmu = %d ", currentMu->idMu);
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

    printf(" removed ");
    return 0;
}

int removeFirst(struct Univers *univers)
{
    struct MU *tmp;
    struct MU *startPopulation = univers->population->startPopulation;

    if (startPopulation == NULL)
        return -1;
    printf("  test ");
    tmp = startPopulation->next;

    freeMu(startPopulation);

    univers->population->startPopulation = tmp;

    // printf(" %d %d", univers->population->startPopulation->idMu, univers->population->startPopulation->next->idMu);
    printf(" removed ");
    return 0;
}