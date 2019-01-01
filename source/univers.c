#include "../proto/supervisor.h"

void initiateUnivers(struct Univers *univers, int version, int lastChildId, int population, struct MU *Mus, struct Land *land)
{
    univers->version = 1;
    univers->lastChildId = lastChildId;
    univers->population = population;
    univers->age = 0;
    univers->perenity = 100;
    univers->Land = land;
    univers->MUs = Mus;
}