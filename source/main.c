#include "../proto/supervisor.h"

int main(int argc, char **argv)
{
    struct MU *MUs;
    struct MU son;
    int population = 10;
    MUs = malloc(sizeof(struct MU) * population);
    initiatePool(MUs, population);
    initiatePool(&son, 1);
    population++;

    addMU(MUs, &son);
    printPopulation(MUs, population);

    return 0;
}