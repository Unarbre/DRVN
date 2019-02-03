#include "../proto/supervisor.h"

// Reproduce 2 lucky MUs
// TEMPORARY -> Procreate will be refactored in the futur, when Turn will be implemented
void procreateRound(struct Univers **univers)
{/*
    // TEMPORARY -> No check for languor status
    // TEMPORARY -> No position check for reproduction (proximity)
    struct MU *inter = univers->population->startPopulation;
    while (inter != NULL)
    {

    }
    //struct MU *baby = breed(&(Mus[5]), &(Mus[3]), lastChild, population);
    //struct MU *newPopulation = malloc(sizeof(struct MU) * ((*population) + 1));
    //for (i = 0; i < (*population); i++)
    //{
    //    newPopulation[i] = Mus[i];
    //}
    //newPopulation[*(population)] = *baby;
    //(*population)++;

    //return newPopulation;*/
}

// breed 2 MU's by spliting DNA and return the baby of this epic reproduction
struct MU *breed(struct MU *dad, struct MU *mom, int *id, int *population)
{
    struct MU *baby = malloc(sizeof(struct MU));

    // Share DNA from Dad and Mom
    shareDNA(baby, dad, mom);
    baby->capacity = initiateCapacity(baby->DNA);

    // TEMPORARY -> Will need a function to determine child's position
    baby->position = malloc(sizeof(int) * 2);
    baby->position[0] = 1;
    baby->position[1] = 1;

    baby->idMu = (*id)++;
    baby->status = 1;
    baby->lifePoints = initiateLifePoints(baby->capacity[0]);
    baby->speed = baby->capacity[1];
    baby->children = calloc(50, sizeof(int));
    affectChildren(baby->idMu, dad);
    affectChildren(baby->idMu, mom);
    dad->languor = 0;
    mom->languor = 0;
    return baby;
}

void shareDNA(struct MU *baby, struct MU *dad, struct MU *mom)
{
    int i = 0;
    tiny expression = 'A';
    baby->DNA = malloc(sizeof(tiny *) * 13);
    while (expression <= 'L')
    {
        baby->DNA[i] = malloc(sizeof(tiny) * 3);
        // Will affect to DNA version 1 or 2 from each parents
        baby->DNA[i][0] = expression++;
        baby->DNA[i][1] = dad->DNA[i][(rand() % 2) + 1];
        baby->DNA[i][2] = mom->DNA[i][(rand() % 2) + 1];
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