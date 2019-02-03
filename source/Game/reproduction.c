#include "../../proto/supervisor.h"

int reproduction(struct Univers *univers)
{
    struct MU *currentMu = univers->population->startPopulation;
    while (currentMu != NULL)
    {
        struct Mu ** breedPartner = checkClosePartner(currentMu);
    }
    return 0;
}