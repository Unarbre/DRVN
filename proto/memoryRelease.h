#include "supervisor.h"

void freePopulation(struct Population *population);
void freeMu(struct MU *Mu);
void freePressureForms(tiny ***pressureForms);
void freeLand(struct Land *land);
void freeTiles(struct Tile **tiles, int square);
void freeUnivers(struct Univers *univers);