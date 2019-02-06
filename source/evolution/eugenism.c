#include "../../proto/supervisor.h"

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
        printf("multivers = %d\n", multivers);
        return bestDnaEver(multivers, multiversBestDNA);
    }

    return NULL;
}

tiny *eugenism(int multiversSelection)
{
    char *multiversFileName = createUniversFile(multiversSelection);
    printf("univers : %s\n", multiversFileName);
    int i = 0, j;
    struct GhostMu **ghosts = malloc(sizeof(struct GhostMu *) * 3);
    struct GhostMu *tmpGhost;
    FILE *fUni = fopen(multiversFileName, "r");
    if (fUni == NULL)
        return NULL;

    puts("in!");
    while (!feof(fUni) && i < 3)
    {
        tmpGhost = initiateGhostMu();
        fscanf(fUni, "%d ", &(tmpGhost->id));
        printf("tmpghost ID : %d\n", tmpGhost->id);
        for (j = 0; j < 12; j++)
        {
            fseek(fUni, 1, SEEK_CUR);
            fscanf(fUni, " %d %d ", &(tmpGhost->Dna[j][0]), &(tmpGhost->Dna[j][1]));
        }
        fscanf(fUni, "%d %d %d\n", &(tmpGhost->goodDay), &(tmpGhost->born), &(tmpGhost->death));
        printf("goodDay : %d\n", tmpGhost->goodDay);
        // TEMPORARY : to be adapted to high tier survivors
        if (tmpGhost->goodDay >= 5)
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
    return orderBestDna(ghosts);
}

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

void freeGhosts(struct GhostMu **ghosts)
{
    int i;
    for (i = 0; i < 3; i++)
    {
        free(ghosts[i]);
    }
    free(ghosts);
}

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
            points[j] += ghosts[i]->Dna[j][0] > 99 ? (ghosts[i]->Dna[j][0] - 100) / 10 : ghosts[i]->Dna[j][0] / 10;
            points[j] += ghosts[i]->Dna[j][1] > 99 ? (ghosts[i]->Dna[j][1] - 100) / 10 : ghosts[i]->Dna[j][1] / 10;
        }
    }

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
        printf("%d ", bestDna[i]);
    }
    return bestDna;
}

tiny *bestDnaEver(int multivers, tiny **multiversBestDNA)
{
    printf("multivers : %d", multivers);
    tiny *bestDna = malloc(sizeof(tiny) * 5);
    tiny points[12] = {0};
    int i, j, highAmount, index;
    for (i = 0; i < multivers; i++)
    {
        for (j = 0; j < 5; j++)
        {
            points[multiversBestDNA[i][j]]++;
        }
    }
    for (i = 0; i < 5; i++)
    {
        highAmount = 1;
        for (j = 0; j < 12; j++)
        {
            printf("j : %d\n", points[j]);
            if (points[j] >= highAmount)
            {
                highAmount = points[j];
                index = j;
            }
        }
        bestDna[i] = index;
        printf("%d\n", index);
        points[index] = 0;
    }
    return bestDna;
}