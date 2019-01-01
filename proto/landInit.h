#include "supervisor.h"

void initiateLand(struct Land *land, int square);
tiny *initialisePressures();
tiny ***initiateTiles(int square, tiny *naturePressures);
tiny ***generatePressureForms(int square);
tiny **generatePressurePeaks(int square);

tiny *generateFirstPeak(int square);
tiny *generateSecondPeak(tiny *firstPeak, int edge, int TopBot);
tiny *generateVPeak(tiny *initialePeak, int edge, int leftRight);
int generateEdge(int square);
int guessTopBot(int square, tiny *firstPeak, int edge);
int guessLeftRight(int square, tiny *firstPeak, int edge);
tiny ***affectTilesPressures(int square, tiny *naturePressures, tiny ***pressureForms);
tiny pOnTile(tiny **peaks, tiny pressure, int x, int y);
int fPeaks(tiny **peaks);
tiny *initiateGeoPressures();
int isOnSquare(tiny **peaks, int firstPeak, int edge, int x, int y);
