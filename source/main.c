#include "../proto/supervisor.h"

int main(int argc, char **argv)
{
    struct MU *MUs;
    struct MU son;
    int population = 10;
    MUs = malloc(sizeof(struct MU) * population);
    initiatePool(MUs, population);

    addMU(MUs, &son, &population);
    printPopulation(MUs, population);

    return 0;
}