#include "../proto/supervisor.h"

// Initiate the population
void initiatePopulation(struct MU *Mus, int MusAmount, int *idMu, int squareSize, int population)
{
    int i;
    for (i = 0; i < MusAmount; i++, Mus++, (*idMu)++)
    {
        printf("In ! ");
        Mus->ADN = initialiseADN();
        printf("out");
        Mus->idMU = (*idMu);
        Mus->position = initialisePosition(*idMu, squareSize, population);
    }
}

//  Initialise Land's parameters
void initiateLand(struct Land *land, int square)
{
    land->size = square;
}

// Return an array of Strand X 2 ADN expressions
tiny **initialiseADN()
{
    tiny **ADN = malloc(sizeof(tiny *) * 12);
    tiny expression = 'A';

    int i, j;
    for (i = 0; i < 12; i++, expression++)
    {
        ADN[i] = malloc(sizeof(tiny) * 3);
        ADN[i][0] = expression;
        for (j = 1; j < 3; j++)
        {
            ADN[i][j] = (rand() % 200);
        }
    }   
    printf("Function ok");
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
