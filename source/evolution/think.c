#include "../../proto/supervisor.h"

struct Rules *initiateRules()
{
    struct Rules *rules = malloc(sizeof(struct Rules));
    rules->bestDna = fetchBestDna();

    return rules;
}

tiny thinkDNA(int strand, tiny *bestDna)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if (bestDna != NULL)
        {

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
    }

    return rand() % 200;
}