#include "../../proto/supervisor.h"

// loop for the game
int startGame(struct Univers *univers)
{
    char command[2];
    struct MU *currentMu;

    currentMu = univers->population->startPopulation;

    for (int i = 0; i < univers->population->density; i++)
    {
        printf("\n idMu : %d  ", currentMu->idMu);
        printf(" position %d  ", currentMu->position[0]);
        printf(" %d ", currentMu->position[1]);
        currentMu = currentMu->next;
    }
    printf("s pour commencer\n");
    fgets(command, 2, stdin);

    // graphGenerateWorld(univers);

    while (command[0] == 's' && univers->age < 15 && univers->population->startPopulation != NULL)
    {
        printf("pap %d\n", univers->population->startPopulation->idMu);
        //move Mu
        movement(univers);

        // change status and lifePoints of each Mu
        survival(univers);
        death(univers);
        univers->age += 1;
        printf("\nageUnivers : %d\n\n", univers->age);
        currentMu = univers->population->startPopulation;
    }
    return 0;
}

// deltete mu, free positions, clean land
int death(struct Univers *univers)
{
    struct MU * currentMu = univers->population->startPopulation;
    
    printf("startPopulation %d\n", currentMu->idMu);
    while(currentMu->next != NULL)
    {
        printf("\nidmu : %d lifepoints : %d ", currentMu->idMu, currentMu->lifePoints);
        if (currentMu->lifePoints <= 0)
        {
            removeMu(univers, currentMu);
            univers->population->density --;
        }
        currentMu = currentMu->next;
    }
    return 0;
}

int removeMu(struct Univers * univers, struct MU *currentMu)
{
    struct MU * startPopulation = univers->population->startPopulation;
    struct MU *population = startPopulation;

    printf(" indexmu = %d ", currentMu->idMu);
    if(currentMu->idMu < 0)
        return -1;
    if(currentMu->idMu == startPopulation->idMu)
        return removeFirst(univers);
    while(population->next->idMu != currentMu->idMu)
    {
        population = population->next;
    }
    population->next = currentMu->next;
    freeMu(currentMu);
    printf(" removed ");
    return 0;
}

int removeFirst(struct Univers * univers)
{
    struct MU * tmp;
    struct MU * startPopulation = univers->population->startPopulation;

    if (startPopulation == NULL || startPopulation->next == NULL)
        return -1;
    printf("  test ");
    tmp = startPopulation->next;
    freeMu(startPopulation);
    univers->population->startPopulation = tmp;

    // printf(" %d %d", univers->population->startPopulation->idMu, univers->population->startPopulation->next->idMu);
    printf(" removed ");
    return 0;
}