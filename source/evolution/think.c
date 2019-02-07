#include "../../proto/supervisor.h"

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
                    return (rand() % 110) + 40;
                    break;
                case 1:
                    return (rand() % 2) ? 40 : rand() % 40;
                    break;
                case 2:
                    return (rand() % 70) + 30;
                    break;
                case 3:
                    return rand() % 100 + 99;
                    break;
                default:
                    return rand() % 50;
                }
            }
        }
    }

    return rand() % 200;
}