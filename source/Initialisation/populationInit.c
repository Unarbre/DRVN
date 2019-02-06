#include "../../proto/supervisor.h"

// POPULATION INITIALISATION

struct Population *initiatePopulation(struct Land *land, int MusAmount, int *idMu, int squareSize)
{
    struct Population *population = malloc(sizeof(struct Population));
    population->startPopulation = generatePopulation(land, MusAmount, idMu, squareSize);
    population->density = MusAmount;
    return population;
}

// generate MU in the population
struct MU *generatePopulation(struct Land *land, int MusAmount, int *idMu, int squareSize)
{
    int i;
    struct MU *startPopulation = NULL;
    tiny *bestDna = fetchBestDna();

    for (i = 0; i < MusAmount; i++)
    {
        // initialise next MU in the startPopulation
        addElderChild(land, &startPopulation, idMu, MusAmount, squareSize, bestDna);
    }
    if (bestDna != NULL)
        free(bestDna);
    return startPopulation;
}

void addElderChild(struct Land *land, struct MU **startPopulation, int *idMu, int MusAmount, int squareSize, tiny *bestDna)
{
    struct MU *newChild = malloc(sizeof(struct MU));

    // Child Initialisation
    newChild->position = initialisePosition(*idMu, squareSize, MusAmount);
    newChild->idMu = MusAmount - (*idMu)++;
    // link Mu and its tile
    land->tiles[newChild->position[0]][newChild->position[1]].Mu = newChild;
    newChild->status = 1;
    // generate random DNA

    newChild->DNA = initialiseDNA(bestDna);
    // transform DNA to usable values
    newChild->capacity = initiateCapacity(newChild->DNA);
    newChild->lifePoints = initiateLifePoints(newChild->capacity[0]);
    newChild->sexAppeal = newChild->capacity[1];
    newChild->languor = 0;
    newChild->birthDate = 0;
    // set nuùber of possible childrens to 50
    newChild->children = initialiseChildren();
    // Child inserted at the begining
    newChild->next = *(startPopulation);
    *startPopulation = newChild;
    puts("life");
}

int *initialiseChildren()
{
    int *childArray = malloc(sizeof(int) * 50);
    int i;

    for (i = 0; i < 50; i++)
    {
        childArray[i] = -1;
    }
    return childArray;
}

// Return an array of Strand X 2 DNA expressions
tiny **initialiseDNA(tiny *bestDna)
{
    tiny **DNA = malloc(sizeof(tiny *) * 12);
    tiny expression = 'A';

    int i, j;
    for (i = 0; i < 12; i++, expression++)
    {
        // 3 Elements. 1 -> DNA letter. 2 -> First Allele. 3-> 2nd Allele
        DNA[i] = malloc(sizeof(tiny) * 3);
        DNA[i][0] = expression;
        for (j = 1; j < 3; j++)
        {
            puts("ok");

            DNA[i][j] = thinkDNA(i, bestDna);
            printf("DNA %d: %d\n", i, DNA[i][j]);
        }
    }
    puts("ok1");

    return DNA;
}

// Return an array filled with Capacity, by interpreting  DNA
int *initiateCapacity(tiny **DNA)
{
    int i = 0;
    int *capacity = malloc(sizeof(int) * 12);
    while (i < 12)
    {
        // Check Dominant and recessives alleles
        if ((DNA[i][1] > 99 && DNA[i][2] > 99) || (DNA[i][1] <= 99 && DNA[i][2] <= 99))
        {
            DNA[i][1] > 99 ? capacity[i] = ((DNA[i][1] - 100) + (DNA[i][2] - 100)) / 2 : (capacity[i] = (DNA[i][1] + DNA[i][2]) / 2);
        }
        else
        {
            (DNA[i][1] > 99) ? (capacity[i] = DNA[i][1] - 100) : (capacity[i] = DNA[i][2] - 100);
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
    printf("%d\n", idMu);
    int *position = malloc(sizeof(int) * 2);

    position[0] = idMu / squareSize;

    position[1] = idMu % squareSize;
    // position[1] = (squareSize % population == 0 ? (idMu * (squareSize / population)) % squareSize : idMu % squareSize);

    return position;
}
