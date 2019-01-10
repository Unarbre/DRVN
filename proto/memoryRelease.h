#include "supervisor.h"

void freeMus(struct MU *Mus, int population);
void freeMu(struct MU *Mu);
void freePressureForms(tiny ***pressureForms);
void freeLand(struct Land *land);
void freeTiles(struct Tile **tiles, int square);
void freeUnivers(struct Univers *univers);