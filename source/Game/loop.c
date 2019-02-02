#include "../../proto/supervisor.h"

// loop for the game
int startGame(struct Univers *univers)
{
    char command[2];
    struct MU *currentMu;

    currentMu = univers->population->startPopulation;

    currentMu->lifePoints += 50;
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
        // for(int i = 0; i < univers->population->density; i++)
        // {
        //     printf("\n idMu : %d  ", currentMu->idMu);
        //     printf(" life %d  ", currentMu->lifePoints);
        //     currentMu = currentMu->next;
        // }
        // printf("test\n");
    }
    return 0;
}

// deltete mu, free positions, clean land
int death(struct Univers *univers)
{
    int i;
    struct MU * currentMu = univers->population->startPopulation;

    printf("startPopulation %d\n", currentMu->idMu);
    for(i = 0; i < univers->population->density; i++)
    {
        printf("\nidmu : %d lifepoints : %d ", currentMu->idMu, currentMu->lifePoints);
        if(currentMu->lifePoints <= 0)
        {
            removeMu(univers->population->startPopulation, currentMu);
            univers->population->density --;
        }
        if(currentMu->next != NULL)
            currentMu = currentMu->next;
    }
    return 0;
}

int removeMu(struct MU * startPopulation, struct MU *currentMu)
{
    struct MU *population = startPopulation;

    printf(" indexmu = %d ", currentMu->idMu);
    if(currentMu->idMu < 0)
        return -1;
    if(currentMu->idMu == 0)
        return removeFirst(startPopulation);
    while(population->next->idMu != currentMu->idMu)
    {
        population = population->next;
    }
    population->next = currentMu->next;
    free(currentMu);
    printf(" removed ");
    return 0;
}

int removeFirst(struct MU * startPopulation)
{
    struct MU * tmp;

    printf("  test ");
    if(startPopulation ==  NULL || startPopulation->next == NULL)
        return -1;
    printf("  test ");
    tmp = startPopulation->next;
    startPopulation = tmp;
    free(tmp);
    printf(" %d ", startPopulation->idMu);
    printf(" removed ");
    return 0;
}