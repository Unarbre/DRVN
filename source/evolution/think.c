#include "../../proto/supervisor.h"

struct Rules *initiateRules()
{
    struct Rules *rules = malloc(sizeof(struct Rules));
    rules->bestDna = fetchBestDna();
    int i;
    for (i = 0; i < 5; i++)
        printf("bestDna : %d\n", rules->bestDna[i]);

    return rules;
}

tiny thinkDNA(int strand, tiny *bestDna)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("bestDNA %d : %d\n", i, bestDna[i]);
        if (strand == bestDna[i])
        {
            switch (i)
            {
            case 0:
                return (rand() % 160) + 40;
                break;
            case 1:
                return (rand() % 2) ? 99 : 199;
                break;
            case 2:
                return (rand() % 30) + 70;
                break;
            case 3:
                return 60;
                break;
            default:
                return 0;
            }
        }
    }

    return rand() % 200;
}