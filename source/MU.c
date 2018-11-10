// Declaration of MU's structure
#include "../proto/supervisor.h"

void initStruct(struct MU *str, int number)
{
    int i;
    for (i = 0; i < number; i++)
    {
        str->heat = 30;
        str->pressure = 30;
        str->skin = 10;
        str++;
    }
}

void addMU(struct MU *geneticPool, struct MU newMU)
{
    int i;
    for (i = 0; i < sizeof(newMU); i++)
    {
        geneticPool[sizeof(geneticPool)] = newMU;
    }
}

void braid(struct MU *dad, struct MU *mom)
{
}