// Declaration of MU's structure
#include "../proto/supervisor.h"

void initiatePopulation(struct MU *str, int number)
{
    int i;
    for (i = 0; i < number; i++)
    {
        str->heat = 30;
        printf("%d : %d,", i, str->heat);
        str->pressure = 30;
        str->skin = 10;
        str++;
    }
}

struct MU *addMU(struct MU *MUnivers, struct MU newMU, int *population)
{
    int i;
    // Declaration of a new MUnivers that will be returned
    struct MU *newUnivers = malloc(sizeof(struct MU) * (*population) + 1);

    // Filling new Univers with previous MU
    for (i = 0; i < (*population); i++)
    {
        newUnivers[i] = MUnivers[i];
    }

    // Adding of the new MU
    newUnivers[i] = newMU;

    // Incrementation of the population
    (*population)++;

    return newUnivers;
}

void breed(struct MU *dad, struct MU *mom)
{
}