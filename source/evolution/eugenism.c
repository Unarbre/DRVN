#include "../../proto/supervisor.h"

// fetch best DNA from all previous univers
tiny *fetchBestDna()
{
    int i;
    tiny **multiversBestDNA = NULL;
    int multivers = getVersion() - 1;
    if (multivers)
    {
        multiversBestDNA = malloc(sizeof(tiny *) * multivers);
        for (i = 0; i < multivers; i++)
        {
            multiversBestDNA[i] = eugenism(i + 1);
        }
        return bestDnaEver(multivers, multiversBestDNA);
    }

    return NULL;
}

// Fetch best DNA from a multiversSelection Univers
tiny *eugenism(int multiversSelection)
{
    char *multiversFileName = createUniversFile(multiversSelection);
    int i = 0, j;
    struct GhostMu **ghosts = malloc(sizeof(struct GhostMu *) * 3);
    struct GhostMu *tmpGhost;
    FILE *fUni = fopen(multiversFileName, "r");
    if (fUni == NULL)
        return NULL;
    // While file is not a the end, or GoodMus are already filled
    while (!feof(fUni) && i < 3)
    {
        tmpGhost = initiateGhostMu();
        fscanf(fUni, "%d ", &(tmpGhost->id));
        for (j = 0; j < 12; j++)
        {
            fseek(fUni, 1, SEEK_CUR);
            fscanf(fUni, " %d %d ", &(tmpGhost->Dna[j][0]), &(tmpGhost->Dna[j][1]));
        }
        fscanf(fUni, "%d %d %d\n", &(tmpGhost->goodDay), &(tmpGhost->born), &(tmpGhost->death));
        // TEMPORARY : to be adapted to high tier survivors
        if (tmpGhost->goodDay >= 3)
        {
            ghosts[i] = tmpGhost;
            i++;
        }
        else
        {
            free(tmpGhost);
        }
    }
    fclose(fUni);
    // Return best dnas from best Mus
    return orderBestDna(ghosts);
}

// Initiate a ghost 
struct GhostMu *initiateGhostMu()
{
    int i;
    struct GhostMu *ghost = malloc(sizeof(struct GhostMu));
    ghost->Dna = malloc(sizeof(int *) * 12);

    for (i = 0; i < 12; i++)
    {
        ghost->Dna[i] = malloc(sizeof(int) * 2);
    }
    return ghost;
}

// Free ghost
void freeGhost(struct GhostMu *ghost)
{
    int i;
    for (i = 0; i < 12; i++)
    {
        free(ghost->Dna[i]);
    }
    free(ghost->Dna);
    free(ghost);
}

// Free last ghosts from the eugenism
void freeGhosts(struct GhostMu **ghosts)
{
    int i;
    for (i = 0; i < 3; i++)
    {
        free(ghosts[i]);
    }
    free(ghosts);
}

// Order  DNA from one multivers and return its 5 best dna
tiny *orderBestDna(struct GhostMu **ghosts)
{
    tiny points[12] = {0};
    int index, highAmount;
    tiny *bestDna = malloc(sizeof(tiny) * 5);
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 12; j++)
        {
            // GIve points to DNA to order them after
            points[j] += ghosts[i]->Dna[j][0] > 99 ? (ghosts[i]->Dna[j][0] - 100) / 10 : ghosts[i]->Dna[j][0] / 10;
            points[j] += ghosts[i]->Dna[j][1] > 99 ? (ghosts[i]->Dna[j][1] - 100) / 10 : ghosts[i]->Dna[j][1] / 10;
        }
    }
    // Simple algo to return best DNAs and fill the bestDna array with
    for (i = 0; i < 5; i++)
    {
        highAmount = 1;
        for (j = 0; j < 12; j++)
        {
            if (points[j] > highAmount)
            {
                highAmount = points[j];
                index = j;
            }
        }
        bestDna[i] = index;
        points[index] = 0;
    }

    freeGhosts(ghosts);
    for (i = 0; i < 5; i++)
    {
    }
    return bestDna;
}

// Order best DNA from all precedent univers
tiny *bestDnaEver(int multivers, tiny **multiversBestDNA)
{
    tiny *bestDna = malloc(sizeof(tiny) * 5);
    tiny points[12] = {0};
    int i, j, highAmount, index;
    for (i = 0; i < multivers; i++)
    {
        for (j = 0; j < 5; j++)
        {
            // give points to dna, depending of the whole univers results on the eugenism system
            points[multiversBestDNA[i][j]]++;
        }
    }
    // Simple ordering algorithm
    for (i = 0; i < 5; i++)
    {
        highAmount = 1;
        for (j = 0; j < 12; j++)
        {
            if (points[j] >= highAmount)
            {
                highAmount = points[j];
                index = j;
            }
        }
        bestDna[i] = index;
        points[index] = 0;
    }
    return bestDna;
}