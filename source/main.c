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
    breed(&(Mus[3]), &(Mus[5]), &idMu, &population);

    freeMus(Mus, 10);
    return 0;
}