#include "../proto/supervisor.h"

// test
int main(int argc, char **argv)
{
    srand(time(NULL));
    struct MU *Mus;
    Mus = malloc(sizeof(struct MU) * 10);
    int idMu = 0;
    int population = 10;
    int size = 50;
    struct Land land;
    initiateLand(&land, size);
    initiatePopulation(Mus, 10, &idMu, land.size, 10);
    Mus = procreate(&population, &idMu, Mus);
    printf("out");

    freeMus(Mus, population);
    freeLand(&land);
    return 0;
}