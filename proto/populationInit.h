#include "supervisor.h"
struct Population *initiatePopulation(struct Land *land, int MusAmount, int *idMu, int squareSize);
struct MU *generatePopulation(struct Land *land, int MusAmount, int *idMu, int squareSize);
void addElderChild(struct Land *land, struct MU **startPopulation, int *idMu, int MusAmount, int squareSize, tiny *bestDna);
int *initialisePosition(int idMu, int squareSize, int population);
tiny **initialiseDNA(tiny *bestDna);
int *initiateCapacity(tiny **DNA);
int initiateLifePoints(tiny geneA);
int *initialiseChildren();