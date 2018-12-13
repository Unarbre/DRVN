#include "supervisor.h"

void initiateLand(struct Land *Land, int square);
void initiatePopulation(struct MU *Mus, int MusAmount, int *idMu, int squareSize, int population);
int *initialisePosition(int idMu, int squareSize, int population);
tiny **initialiseADN();
