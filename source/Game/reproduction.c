#include "../../proto/supervisor.h"

// Generic function, parcouring each MU and trying to reproduce
int reproduction(struct Univers *univers)
{
    struct MU *currentMu = univers->population->startPopulation;
    int i, partnerAmount;
    struct MU **breedPartner = NULL;
    while (currentMu != NULL)
    {
        // Check if MU can try to reproduce, depending of its statut
        if (tryBreed(currentMu) && currentMu->languor == 0)
        {
            partnerAmount = 0;
            breedPartner = checkClosePartner(univers, currentMu, &partnerAmount);

            if (partnerAmount != 0)
            {
                breedPartner = orderedSexPartner(breedPartner, partnerAmount, currentMu->sexPreference);
                for (i = 0; i < partnerAmount; i++)
                {
                    if (breedPartner[i]->languor == 0 && currentMu->languor == 0)
                    {
                        breed(currentMu, breedPartner[i], univers);
                    }
                }
            }

            if (breedPartner != NULL)
            {
                freeBreedPartner(breedPartner, partnerAmount);
            }
        }

        currentMu = currentMu->next;
    }
    return 0;
}

int tryBreed(struct MU *mu)
{
    switch (mu->status)
    {
    case 0:
        if (!luckBreedTest(8))
            return 0;
        break;
    case 1:
        if (!luckBreedTest(4))
            return 0;
        break;
    default:;
    }

    return 1;
}

int luckBreedTest(int round)
{
    int i;
    for (i = 0; i < round; i++)
    {
        if (!(rand() % 3))
            return 0;
    }
    return 1;
}

// This function is amazing.
struct MU **checkClosePartner(struct Univers *univers, struct MU *currentMu, int *partnerAmount)
{
    int x = currentMu->position[0] - 1, y = currentMu->position[1] - 1;

    int xs[3] = {x, x + 1, x + 2};
    int ys[3] = {y, y + 1, y + 2};
    int i = 0;
    struct MU **closePartner = malloc(sizeof(struct MU *) * 9);
    for (; x <= xs[2]; x++)
    {
        y = ys[0];
        for (; y <= ys[2]; y++)
        {
            closePartner[i] = NULL;
            if ((x != xs[1] || y != ys[1]) && ((x >= 0 && x < univers->land->size) && (y >= 0 && y < univers->land->size)) && univers->land->tiles[x][y].Mu != NULL)
            {
                (*partnerAmount)++;
                if (univers->land->tiles[x][y].Mu != NULL)
                    closePartner[i] = univers->land->tiles[x][y].Mu;
            }
            i++;
        }
    }

    return closePartner;
}

struct MU **orderedSexPartner(struct MU **sexPartner, int numPartner, int sexPreference)
{
    struct MU **orderedSexP = malloc(sizeof(struct MU *) * numPartner);
    int i, j = 0;
    for (i = 0; i < 9; i++)
    {
        if (sexPartner[i] != NULL)
        {
            orderedSexP[j] = sexPartner[i];
            sexPartner[i] = NULL;
            j++;
        }
    }
    free(sexPartner);
    orderedSexP = orderSexAttraid(orderedSexP, numPartner, sexPreference);
    return orderedSexP;
}

struct MU **orderSexAttraid(struct MU **sexPartner, int numPartner, int sexPreference)
{
    int i, j;
    struct MU *temp;
    if (numPartner <= 1)
    {
        return sexPartner;
    }

    for (i = 0; i < numPartner - 1; i++)
    {
        for (j = 1; j < numPartner; j++)
        {
            if (sexPartner[i]->capacity[sexPreference] < sexPartner[j]->capacity[sexPreference])
            {
                temp = sexPartner[i];
                sexPartner[i] = sexPartner[j];
                sexPartner[j] = temp;
            }
        }
    }
    return sexPartner;
}

// breed 2 MU's by spliting DNA and affect the baby of this epic reproduction to the StartPopulation pointer
void breed(struct MU *dad, struct MU *mom, struct Univers *univers)
{
    struct MU *baby = malloc(sizeof(struct MU));

    // Share DNA from Dad and Mom
    shareDNA(baby, dad, mom);
    baby->capacity = initiateCapacity(baby->DNA);

    // Will determine child's position and if there is place to pop the baby
    if (!(checkAffectPosition(mom, &baby, univers)))
    {
        return;
    }
    baby->languor = 1;
    baby->birthDate = univers->age;
    baby->idMu = univers->lastChildId++;
    baby->status = 1;
    baby->lifePoints = initiateLifePoints(baby->capacity[0]);
    baby->children = initialiseChildren();
    baby->sexPreference = mom->sexPreference;
    affectChildren(baby->idMu, dad);
    affectChildren(baby->idMu, mom);
    dad->languor = 1;
    mom->languor = 1;
    univers->population->startPopulation = insertChild(baby, univers);
    univers->population->density++;
}

// Affect DNA to baby by randomly sliting mom and dad's DNA
void shareDNA(struct MU *baby, struct MU *dad, struct MU *mom)
{
    int i = 0;
    tiny expression = 'A';
    char mutateCounter = (rand() % ('A' - 'Z')) + 'A';
    baby->DNA = malloc(sizeof(tiny *) * 13);
    while (expression <= 'L')
    {
        baby->DNA[i] = malloc(sizeof(tiny) * 3);
        // Will affect to DNA version 1 or 2 from each parents
        baby->DNA[i][0] = expression++;
        baby->DNA[i][1] = dad->DNA[i][(rand() % 2) + 1];
        baby->DNA[i][2] = mom->DNA[i][(rand() % 2) + 1];
        if (mutateCounter == expression - 1)
        {
            baby->DNA[i] = mutate(baby->DNA[i]);
        }
        i++;
    }
}

void affectChildren(int idChildren, struct MU *parent)
{
    int i;
    for (i = 0; parent->children[i] != -1; i++)
    {
    }
    parent->children[i] = idChildren;
}

struct MU *insertChild(struct MU *child, struct Univers *univers)
{
    struct MU *startPopulation = univers->population->startPopulation;
    struct MU *inter = startPopulation;
    child->next = NULL;
    if (inter == NULL)
        return child;

    while (inter->next != NULL)
    {
        inter = inter->next;
    }
    inter->next = child;
    return startPopulation;
}

// This function check
int checkAffectPosition(struct MU *parent, struct MU **child, struct Univers *univers)
{
    int x = parent->position[0] - 1, y = parent->position[1] - 1;
    int *childPosition = malloc(sizeof(int) * 2);
    int xs[3] = {x, x + 1, x + 2};
    int ys[3] = {y, y + 1, y + 2};
    for (; x <= xs[2]; x++)
    {
        y = ys[0];
        for (; y <= ys[2]; y++)
        {
            if ((x != xs[1] || y != ys[1]) && ((x >= 0 && x < univers->land->size) && (y >= 0 && y < univers->land->size)) && univers->land->tiles[x][y].Mu == NULL)
            {
                childPosition[0] = x;
                childPosition[1] = y;
                (*child)->position = childPosition;
                univers->land->tiles[x][y].Mu = (*child);
                return 1;
            }
        }
    }
    return 0;
}

void freeBreedPartner(struct MU **sexPartners, int numPartner)
{
    int i;
    for (i = 0; i < numPartner; i++)
    {
        sexPartners[i] = NULL;
        free(sexPartners[i]);
    }
}

tiny *mutate(tiny *DNA)
{
    DNA[0] += 50;
    DNA[1] += 50;
    if (DNA[0] > 200)
        DNA[0] -= 100;
    if (DNA[1] > 200)
        DNA[1] -= 100;
    return DNA;
}