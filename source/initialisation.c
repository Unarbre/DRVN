#include "../proto/supervisor.h"

void initiateLand(struct Land *land, int square)
{
    land->size = square;
}

// Initiate the population
void initiatePopulation(struct MU *Mus, int MusAmount, int *idMu, int squareSize, int population)
{
    int i;
    for (i = 0; i < MusAmount; i++, Mus++, (*idMu)++)
    {
        printf("in!");
        printf("ok");
        Mus->idMU = (*idMu);
        Mus->position = initialisePosition(*idMu, squareSize, population);
    }
}

// Return an array of Strand X 2 ADN expressions
tiny **initialiseADN()
{
    tiny **ADN = malloc(sizeof(tiny *) * 12);
    tiny expression = 'A';
    int i, j;
    for (i = 0; i < 12; i++)
    {
        ADN[i] = malloc(sizeof(tiny) * 3);
        ADN[i][0] = expression;
        for (j = 1; j < 3; j++)
        {
            ADN[i][j] = (rand() % 200);
        }
        expression++;
    }
    return ADN;
}

// Generate a position depending of the population and the space allowed.
int *initialisePosition(int idMu, int squareSize, int population)
{

    int *position = malloc(sizeof(int) * 2);
    position[0] = 0;
    position[1] = idMu * (squareSize / population);
    printf("ok");

    return position;
}
