#include "../proto/supervisor.h"

// test
int main(int argc, char **argv)
{
    struct Land land;
    struct MU *MUs;
    int population = 10;
    int idMu = 0;
    int square = 50;
    initiateLand(&land, square);
    initiatePopulation(MUs, 10, &idMu, land.size, population);
    printMu(&(MUs[3]));

    return 0;
}