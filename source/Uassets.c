#include "../proto/supervisor.h"

void printPopulation(struct MU *MUs, int population)
{
    for (int i = 0; i < population; i++)
    {
        /*printf("MU#%d:\n", i + 1);
        printf("Heat : %d\n", MUs[i].heat);
        printf("pressure : %d\n", MUs[i].pressure);
        printf("skin : %d\n", MUs[i].skin);
        */
    }
}

void printMu(struct MU *Mu)
{
    int i = 0;
    printf("Id :%d\n", Mu->idMU);
    printf("position : %d %d\n", Mu->position[0], Mu->position[1]);
    while (i <= 11)
    {

        printf("%c: %d %d\n", Mu->ADN[i][0], Mu->ADN[i][1], Mu->ADN[i][2]);
        i++;
    }
    i = 0;
    while (i <= 11)
    {
        printf("Capacity %c : %d\n", Mu->ADN[i][0], Mu->capacity[i]);
        i++;
    }

    printf("Life Points : %d", Mu->lifePoints);
}