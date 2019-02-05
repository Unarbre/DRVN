#include "../../proto/supervisor.h"

struct Rules *initiateRules()
{
    struct Rules *rules = malloc(sizeof(struct Rules));
    rules->bestDna = fetchBestDna();

    return rules;
}

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
    }
    else
    {
        return NULL;
    }
    return NULL;
}

tiny *eugenism(int multiversSlection)
{
    int i;
    for (i = 0; i < multiversSlection; i++)
    {
    }
    return NULL;
}