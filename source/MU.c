// Declaration of MU's structure
#include "../proto/supervisor.h"

// Initiate the population
void initiatePopulation(struct MU *MUs, int number, int *idMU, int squareSize, int population)
{
    int i;
    for (i = 0; i < number; i++, MUs++)
    {
        MUs->idMU = (*idMU)++;
        MUs->position = generatePosition(squareSize, MUs, population);
    }
}

// Return random position
int *generatePosition(int squareSize, struct MU *MUs, int population)
{
    int *position = malloc(sizeof(int) * 2);
    position[0] = rand() % squareSize;
    position[1] = rand() % squareSize;
    if (checkPosition(squareSize, position, MUs, population))
    {
        return generatePosition(squareSize, MUs, population);
    }
    return position;
}

// Check position availability
int checkPosition(int squareSize, int *position, struct MU *MUs, int population)
{
    int i;
    // Check if maximal size is respected
    if (position[0] > squareSize || position[1] > squareSize)
    {
        return 1;
    }

}

// Add an MU to the already setup MU's pool
struct MU *addMU(struct MU *MUnivers, struct MU newMU, int *population)
{
    int i;
    // Declaration of a new MUnivers that will be returned
    struct MU *newUnivers = malloc(sizeof(struct MU) * (*population) + 1);

    // Filling new Univers with previous MU
    for (i = 0; i < (*population); i++)
    {
        newUnivers[i] = MUnivers[i];
    }

    // Adding of the new MU
    newUnivers[i] = newMU;

    // Incrementation of the population
    (*population)++;

    return newUnivers;
}

void breed(struct MU *dad, struct MU *mom)
{
}