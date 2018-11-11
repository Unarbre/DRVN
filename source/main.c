#include "../proto/supervisor.h"
// test
int main(int argc, char **argv)
{
    struct MU *MUs;
    struct MU son;
    int population = 10;
    MUs = malloc(sizeof(struct MU) * population);
    initiatePopulation(MUs, population);
    printPopulation(MUs, population);

    initiatePopulation(&son, 1);

    MUs = addMU(MUs, son, &population);
    printPopulation(MUs, population);

    return 0;
}