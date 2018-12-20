#include "../proto/supervisor.h"

// test
int main(int argc, char **argv)
{
    srand(time(NULL));
    struct MU *Mus;
    Mus = malloc(sizeof(struct MU) * 10);
    int idMu = 0;
    int population = 10;
    struct Land land;
    initiateLand(&land, 50);
    initiatePopulation(Mus, 10, &idMu, land.size, 10);
    Mus = procreate(&population, &idMu, Mus);
    printMu(&Mus[population - 1]);
    printf("%d", population);
    freeMus(Mus, population);
    return 0;
}