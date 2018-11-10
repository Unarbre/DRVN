#ifndef SUPERVISOR
#define SUPERVISOR

#include "MU.h"

void addMU(struct MU *geneticPool, struct MU * newMU);
void braid(struct MU *dad, struct MU *mom);

#endif