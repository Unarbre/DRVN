#include "../proto/supervisor.h"

void freeMus(struct MU *Mus, int population)
{
    int i;

    // For each MU, free them
    for (i = 0; i < population; i++)
    {
        printMu(&(Mus[i]));
        freeMu(&(Mus[i]));
    }
}

void freeMu(struct MU *Mu)
{
    int i = 0;

    // Free ADN's array
    while (Mu->ADN[i][0] != 'L')
    {
        if (Mu->ADN[i] != NULL)
            free(Mu->ADN[i]);
        i++;
    }

    // Free ADN
    if (Mu->ADN != NULL)
        free(Mu->ADN);

    // Free position
    if (Mu->position != NULL)
        free(Mu->position);
}