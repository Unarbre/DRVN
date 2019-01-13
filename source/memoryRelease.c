#include "../proto/supervisor.h"

// Free PressureForms (Land initialisation tool)
void freePressureForms(tiny ***pressureForms)
{
    int i, j;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (pressureForms[i][j] != NULL)
                free(pressureForms[i][j]);
            printf(" ok!");
        }
        if (pressureForms[i] != NULL)
            free(pressureForms[i]);
    }
    if (pressureForms != NULL)
        free(pressureForms);
}
/** Memory gestion Functionalities
 * 
 * 
 * 
*/

void freeUnivers(struct Univers *univers)
{
    freeLand(univers->land);
    freePopulation(univers->population);
    free(univers);
}

// Population FREE
void freePopulation(struct Population *population)
{
    struct MU *inter;
    while (population->startPopulation != NULL)
    {
        inter = population->startPopulation;
        population->startPopulation = population->startPopulation->next;
        if (inter->ADN != NULL && inter->ADN[0] != NULL)
        {
            freeMu(inter);
            free(inter);
        }
    }
    free(population->startPopulation);
    free(population);
}

void freeMu(struct MU *Mu)
{
    if (Mu != NULL)
    {
        int i = 0;

        // Free ADN's array
        while (Mu->ADN[i][0] <= 'L')
        {
            free(Mu->ADN[i]);
            i++;
        }

        // Free ADN
        if (Mu->ADN != NULL)
            free(Mu->ADN);

        if (Mu->capacity != NULL)
            free(Mu->capacity);

        // Free position
        if (Mu->position != NULL)
            free(Mu->position);

        if (Mu->children != NULL)
            free(Mu->children);
    }
}

// Land FREE
void freeLand(struct Land *land)
{
    free(land->worldPressure);
    freeTiles(land->tiles, land->size);
}

void freeTiles(struct Tile **tiles, int square)
{
    int i;
    if (tiles != NULL)
    {
        for (i = 0; i < square; i++)
        {
            if (tiles[i] != NULL)
            {
                free(tiles[i]);
            }
        }
        free(tiles);
    }
}
