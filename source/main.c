#include "../proto/supervisor.h"

// test
int main(int argc, char **argv)
{
    srand(time(NULL));
    struct MU *Mus;
    int idMu = 0;
    int population = 10;
    int size = 50;
    struct Land land;
    Mus = malloc(sizeof(struct MU) * 10);
    initiateLand(&land, size);
    initiatePopulation(Mus, 10, &idMu, land.size, 10);
    struct Univers univers;
    initiateUnivers(&univers, 1, idMu, population, Mus, &land);

    univers.MUs = procreate(&(univers.population), &(univers.lastChildId), univers.MUs, univers.age);
    printMu(&(univers.MUs[5]));
    freeUnivers(&univers);
    printf("outiout!");
    return 0;
}