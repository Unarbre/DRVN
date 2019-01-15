#include "supervisor.h"

int resistance(struct Univers *univers, struct MU * mu);
int testStatus(struct Univers *univers, struct Population *population, struct Land *land, struct MU ** currentMu, int idMu);
int startGame(struct Univers *univers, struct Population *population, struct Land *land);