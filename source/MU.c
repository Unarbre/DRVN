#include "../proto/supervisor.h"

/* !!!! TEMPORARY FUNCTION !!!!! MU WILL NOT BE GENERATE BUT CREATE AS THE RESULT OF A BREED OF TWO MU !!!!! 
Initialize an MU independently of the first initialisation */
void generateMu(struct MU *Mu, int *idMu, int population, int squareSize, struct MU *Mus)
{
    Mu->idMU = (*idMu)++;
    Mu->ADN = initialiseADN();
    Mu->capacity = generateCapacity(Mu->ADN);
    Mu->position = generatePosition(squareSize, Mus, population);
    Mus->children = NULL;
}



int **generateCapacity(unsigned char **ADN)
{
    int **capacity = malloc(sizeof(int) * 2);
    return capacity;
}

// Return random position
int *generatePosition(int squareSize, struct MU *Mus, int population)
{
    printf("%d", squareSize);

    int *position = malloc(sizeof(int) * 2);
    position[0] = rand() % squareSize;
    position[1] = rand() % squareSize;
    printf("%d%d", position[0], position[1]);

    if (checkPosition(squareSize, position, Mus, population))
    {
        printf("c");

        return generatePosition(squareSize, Mus, population);
    }
    return position;
}

// Check position availability
int checkPosition(int squareSize, int *position, struct MU *Mus, int population)
{
    int i;
    printf("%d", population);

    // Check if maximal size is respected
    if (position[0] > squareSize || position[1] > squareSize)
    {
        return 1;
    }

    // Check if position is equal to another MU's one
    for (i = 0; i < population; i++, Mus++)
    {
        if (position[0] == Mus->position[0] && position[1] == Mus->position[1])
        {
            printf("e");

            return 1;
        }
    }

    return 0;
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