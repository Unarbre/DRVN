// Declaration of MU's structure
#include "../proto/supervisor.h"

void initiatePool(struct MU *str, int number)
{
    int i;
    for (i = 0; i < number; i++)
    {
        str->heat = 30;
        printf("%d,",str->heat);
        str->pressure = 30;
        str->skin = 10;
        str++;
    }
}

void addMU(struct MU *geneticPool, struct MU * newMU, int *population)
{
    initiatePool(newMU, 1);
    geneticPool[sizeof(geneticPool)] = *newMU;
    (*population)++;
}

void braid(struct MU *dad, struct MU *mom)
{
}