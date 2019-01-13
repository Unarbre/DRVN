#include "supervisor.h"
struct Population *initiatePopulation(int MusAmount, int *idMu, int squareSize);
struct MU *generatePopulation(int MusAmount, int *idMu, int squareSize);
void addElderChild(struct MU **startPopulation, int *idMu, int MusAmount, int squareSize);
int *initialisePosition(int idMu, int squareSize, int population);
tiny **initialiseADN();
int *initiateCapacity(tiny **ADN);
int initiateLifePoints(tiny geneA);
