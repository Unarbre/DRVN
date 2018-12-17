#include "../proto/supervisor.h"

// POPULATION INITIALISATION

// Initiate the population
void initiatePopulation(struct MU *Mus, int MusAmount, int *idMu, int squareSize, int population)
{
    int i;
    for (i = 0; i < MusAmount; i++, Mus++, (*idMu)++)
    {
        Mus->idMU = *idMu;
        Mus->ADN = initialiseADN();
        Mus->capacity = initiateCapacity(Mus->ADN);
        Mus->lifePoints = initiateLifePoints(Mus->capacity[0]);
        Mus->position = initialisePosition(*idMu, squareSize, population);
        Mus->children = NULL;
    }
}

// Return an array of Strand X 2 ADN expressions
tiny **initialiseADN()
{
    tiny **ADN = malloc(sizeof(tiny *) * 12 + 1);
    tiny expression = 'A';

    int i, j;
    for (i = 0; i < 12 + 1; i++, expression++)
    {
        ADN[i] = malloc(sizeof(tiny) * 3);
        ADN[i][0] = expression;
        for (j = 1; j < 3; j++)
        {
            ADN[i][j] = (rand() % 200);
        }
    }
    return ADN;
}

// Return an array filled with Capacity
int *initiateCapacity(tiny **ADN)
{
    int i = 0;
    int *capacity = malloc(sizeof(int) * 12);
    while (i < 12)
    {
        // Check Dominant and recessives alleles
        if ((ADN[i][1] > 99 && ADN[i][2] > 99) || (ADN[i][1] <= 99 && ADN[i][2] <= 99))
        {
            ADN[i][1] > 99 ? capacity[i] = ((ADN[i][1] - 100) + (ADN[i][2] - 100)) / 2 : (capacity[i] = (ADN[i][1] + ADN[i][2]) / 2);
        }
        else
        {
            (ADN[i][1] > 99) ? (capacity[i] = ADN[i][1] - 100) : (capacity[i] = ADN[i][2] - 100);
        }
        printf("%c", ADN[i][0]);
        i++;
    }
    return capacity;
}

// Calculate and return life points from gene A (first gene)
int initiateLifePoints(int geneA)
{
    return 5 + (geneA / 2) / 10;
}

// Generate a position depending of the population and the space allowed.
int *initialisePosition(int idMu, int squareSize, int population)
{

    int *position = malloc(sizeof(int) * 2);
    position[0] = 0;
    position[1] = idMu * (squareSize / population);

    return position;
}

//LAND INITIALISATION

//  Initialise Land's parameters

void initiateLand(struct Land *land, int square)
{
    land->size = square;
}