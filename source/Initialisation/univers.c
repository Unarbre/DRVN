#include "../../proto/supervisor.h"

void initiateUnivers(struct Univers *univers, int version, int lastChildId, struct Population *population, struct Land *land)
{
    univers->version = 1;
    univers->lastChildId = lastChildId;
    univers->age = 0;
    univers->perenity = 100;
    univers->land = land;
    univers->population = population;
}