#include "../proto/supervisor.h"

/** Memory gestion Functionalities
 * 
 * 
 * 
*/

void freeMus(struct MU *Mus, int population)
{
    int i;

    // For each MU, free them
    for (i = 0; i < population; i++)
    {
        printMu(&(Mus[i]));
        freeMu(&(Mus[i]));
    }
    free(Mu);
}

void freeMu(struct MU *Mu)
{
    if (MU != NULL)
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
}