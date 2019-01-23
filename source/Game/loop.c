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


    while (command[0] == 's' && univers->age < 15)
    {
        //move Mu
        movement(univers);

        // change status and lifePoints of each Mu
        survival(univers);
        death(univers);
        univers->age += 1;
        printf("\nageUnivers : %d\n\n", univers->age);
    }
    return 0;
}

// deltete mu, free positions, clean land
int death(struct Univers *univers)
{
    int i;
    struct MU * currentMu = univers->population->startPopulation;

    for(i = 0; i < univers->population->density; i++)
    {
        printf("\nidmu : %d lifepoints : %d ", currentMu->idMu, currentMu->lifePoints);
        if(currentMu->lifePoints <= 0)
        {
            removeMu(univers->population->startPopulation, (univers->population->density) - currentMu->idMu);
            univers->population->density --;
        }
        if(currentMu->next != NULL)
            currentMu = currentMu->next;
    }
    return 0;
}

int removeMu(struct MU * startPopulation, int indexMu)
{
    int i;
    struct MU * currentMu = startPopulation;
    struct MU * restChain;
    printf(" indexmu = %d ", indexMu);
    if(indexMu == 0)
        return removeFirst(startPopulation);
    for(i = 0; i < indexMu - 1; i++)
    {
        if(currentMu->next == NULL)
            return -1;
        currentMu = currentMu->next;
    }

    restChain = currentMu->next;
    currentMu->next = restChain->next;
    free(restChain);
    return 0;
}

int removeFirst(struct MU * startPopulation)
{
    struct MU * newFirst;

    printf("\ntest\n");
    newFirst = startPopulation->next;
    free(startPopulation);
    startPopulation = newFirst;
    printf(" %d ", startPopulation->idMu);
    // printf(" %d %d %d", startPopulation->idMu, startPopulation->next->idMu, startPopulation->next->next->idMu);
    return 0;
}