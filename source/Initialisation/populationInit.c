#include "../../proto/supervisor.h"

// POPULATION INITIALISATION

struct Population *initiatePopulation(int MusAmount, int *idMu, int squareSize)
{
    struct Population *population = malloc(sizeof(struct Population));
    population->startPopulation = generatePopulation(MusAmount, idMu, squareSize);
    population->density = MusAmount;
    return population;
}

// generate MU in the population
struct MU *generatePopulation(int MusAmount, int *idMu, int squareSize)
{
    int i;
    struct MU *startPopulation = malloc(sizeof(struct MU));
    for (i = 0; i < MusAmount; i++)
    {
        // initialise next MU in the startPopulation
        addElderChild(&startPopulation, idMu, MusAmount, squareSize);
    }
    return startPopulation;
}

void addElderChild(struct MU **startPopulation, int *idMu, int MusAmount, int squareSize)
{
    struct MU *newChild = malloc(sizeof(struct MU));

    // Child Initialisation
    newChild->position = initialisePosition(*idMu, squareSize, MusAmount);
    newChild->idMu = (*idMu)++;
    newChild->status = 1;
    // generate random DNA
    newChild->ADN = initialiseADN();
    // transform DNA to usable values
    newChild->capacity = initiateCapacity(newChild->ADN);
    newChild->lifePoints = initiateLifePoints(newChild->capacity[0]);
    newChild->speed = newChild->capacity[1];
    newChild->languor = 0;
    newChild->birthDate = 0;
    // set nuber of possible childrens to 50
    newChild->children = calloc(50, sizeof(int));
    
    // Child inserted at the begining
    newChild->next = *(startPopulation);
    *startPopulation = newChild;
}

// Return an array of Strand X 2 ADN expressions
tiny **initialiseADN()
{
    tiny **ADN = malloc(sizeof(tiny *) * 12 + 1);
    tiny expression = 'A';

    int i, j;
    for (i = 0; i < 12 + 1; i++, expression++)
    {
        // 3 Elements. 1 -> ADN letter. 2 -> First Allele. 3-> 2nd Allele
        ADN[i] = malloc(sizeof(tiny) * 3);
        ADN[i][0] = expression;
        for (j = 1; j < 3; j++)
        {
            ADN[i][j] = (rand() % 200);
        }
    }
    return ADN;
}

// Return an array filled with Capacity, by interpreting  ADN
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
        i++;
    }
    return capacity;
}

// Calculate and return life points from gene A (first gene)
int initiateLifePoints(tiny geneA)
{
    return 5 + (geneA / 2) / 10;
}

// Generate a position depending of the population and the space allowed.
int *initialisePosition(int idMu, int squareSize, int population)
{

    int *position = malloc(sizeof(int) * 2);

    position[0] = 0;

    position[1] = (squareSize % population == 0 ? idMu * (squareSize / population) : idMu);

    return position;
}
