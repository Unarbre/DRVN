#include "../proto/supervisor.h"

// Reproduce 2 lucky MUs
// TEMPORARY -> Procreate will be refactored in the futur, when Turn will be implemented
struct MU *procreate(int *population, int *lastChild, struct MU *Mus, int date)
{
    // TEMPORARY -> No check for languor status
    // TEMPORARY -> No position check for reproduction (proximity)
    int i;

    struct MU *baby = breed(&(Mus[5]), &(Mus[3]), lastChild, population);
    struct MU *newPopulation = malloc(sizeof(struct MU) * ((*population) + 1));
    for (i = 0; i < (*population); i++)
    {
        newPopulation[i] = Mus[i];
    }
    newPopulation[*(population)] = *baby;
    (*population)++;

    return newPopulation;
}

// breed 2 MU's by spliting ADN and return the baby of this epic reproduction
struct MU *breed(struct MU *dad, struct MU *mom, int *id, int *population)
{
    struct MU *baby = malloc(sizeof(struct MU));

    // Share ADN from Dad and Mom
    shareADN(baby, dad, mom);
    baby->capacity = initiateCapacity(baby->ADN);

    // TEMPORARY -> Will need a function to determine child's position
    baby->position = malloc(sizeof(int) * 2);
    baby->position[0] = 1;
    baby->position[1] = 1;

    baby->idMU = (*id)++;
    baby->status = 1;
    baby->lifePoints = initiateLifePoints(baby->capacity[0]);
    baby->speed = baby->capacity[1];
    baby->children = calloc(50, sizeof(int));
    affectChildren(baby->idMU, dad);
    affectChildren(baby->idMU, mom);
    dad->languor = 0;
    mom->languor = 0;
    return baby;
}

void shareADN(struct MU *baby, struct MU *dad, struct MU *mom)
{
    int i = 0;
    tiny expression = 'A';
    baby->ADN = malloc(sizeof(tiny *) * 13);
    while (expression <= 'L')
    {
        baby->ADN[i] = malloc(sizeof(tiny) * 3);
        // Will affect to ADN version 1 or 2 from each parents
        baby->ADN[i][0] = expression++;
        baby->ADN[i][1] = dad->ADN[i][(rand() % 2) + 1];
        baby->ADN[i][2] = mom->ADN[i][(rand() % 2) + 1];
        i++;
    }
}

void affectChildren(int idChildren, struct MU *parent)
{
    int i;
    for (i = 0; parent->children[i] != 0; i++)
    {
        printf("not okay");
    }
    parent->children[i] = idChildren;
}
