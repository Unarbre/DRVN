#include "../proto/supervisor.h"

// test
int main(int argc, char **argv)
{
    struct MU *Mus;
    Mus = malloc(sizeof(struct MU) * 10);
    int idMu = 0;
    struct Land land;
    initiateLand(&land, 50);
    initiatePopulation(Mus, 10, &idMu, land.size, 10);
    printMu(&(Mus[4]));

    freeMus(Mus, 10);
    return 0;
}