#include "supervisor.h"

int startGame(struct Univers *univers, struct Population *population, struct Land *land);
int survival(struct Univers *univers, struct Population *population, struct Land *land, struct MU *currentMu);
int changePv(struct Univers *univers, struct Population *population, struct Land *land, struct MU ** PcurrentMu);
int testStatus(struct Univers *univers, struct Population *population, struct Land *land, struct MU ** currentMu);
int resistance(struct Univers *univers, struct MU * mu);
