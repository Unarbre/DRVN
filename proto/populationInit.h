#include "supervisor.h"

void initiateLand(struct Land *land, int square);
void initiatePopulation(struct MU *Mus, int MusAmount, int *idMu, int squareSize, int population);
int *initialisePosition(int idMu, int squareSize, int population);
tiny **initialiseADN();
int *initiateCapacity(tiny **ADN);
