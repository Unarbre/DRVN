#include "../proto/supervisor.h"

void printPopulation(struct MU *MUs, int population)
{
    for (int i = 0; i < population; i++, MUs++)
    {
        printf("MU#%d:\n", i + 1);
        printf("Heat : %d\n", MUs->heat);
        printf("pressure : %d\n", MUs->pressure);
        printf("skin : %d\n", MUs->skin);
    }
}
