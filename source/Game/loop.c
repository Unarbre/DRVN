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

    graphGenerateWorld(univers);

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
<<<<<<< HEAD
    int i;
    struct MU * currentMu = univers->population->startPopulation;

    printf("startPopulation %d\n", currentMu->idMu);
    for(i = 0; i < univers->population->density; i++)
=======
    int i, baseDensity = univers->population->density;
    struct MU *currentMu = univers->population->startPopulation;

    for (i = 0; i < univers->population->density; i++)
>>>>>>> 56f05f8d57ae24a666ded3e2db8a1b7fdf1ccab1
    {
        printf("\nidmu : %d lifepoints : %d ", currentMu->idMu, currentMu->lifePoints);
        if (currentMu->lifePoints <= 0)
        {
<<<<<<< HEAD
            removeMu(univers->population->startPopulation, currentMu);
            univers->population->density --;
=======
            removeMu(univers->population->startPopulation, baseDensity - 1 - currentMu->idMu);
            univers->population->density--;
>>>>>>> 56f05f8d57ae24a666ded3e2db8a1b7fdf1ccab1
        }
        if (currentMu->next != NULL)
            currentMu = currentMu->next;
    }
    return 0;
}

<<<<<<< HEAD
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
=======
int removeMu(struct MU *startPopulation, int indexMu)
{
    int i;
    struct MU *currentMu = startPopulation;
    struct MU *restChain;
    printf(" indexmu = %d ", indexMu);
    if (indexMu < 0)
        return -1;
    if (indexMu == 0)
        return removeFirst(startPopulation);
    

    for (i = 0; i < indexMu; i++)
    {
        if (currentMu->next == NULL)
            return -1;
        currentMu = currentMu->next;
>>>>>>> 56f05f8d57ae24a666ded3e2db8a1b7fdf1ccab1
    }
    population->next = currentMu->next;
    free(currentMu);
    printf(" removed ");
    return 0;
}

int removeFirst(struct MU *startPopulation)
{
<<<<<<< HEAD
    struct MU * tmp;
=======
    struct MU *newFirst;
>>>>>>> 56f05f8d57ae24a666ded3e2db8a1b7fdf1ccab1

    printf("  test ");
    if (startPopulation == NULL || startPopulation->next == NULL)
        return -1;
    printf("  test ");
    tmp = startPopulation->next;
    startPopulation = tmp;
    free(tmp);
    printf(" %d ", startPopulation->idMu);
    printf(" removed ");
    return 0;
}