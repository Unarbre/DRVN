#include "../proto/supervisor.h"

// test
int main(int argc, char **argv)
{
    struct Land Land;
    struct MU *MUs;
    int population = 10;
    int idMu = 0;
    initiatePopulation(MUs, 10, &idMu, Land.size, population);
    printMu(&(MUs[3]));

    return 0;
}