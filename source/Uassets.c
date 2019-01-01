#include "../proto/supervisor.h"

void printMu(struct MU *Mu)
{
    int i = 0;
    printf("\nId :%d\n", Mu->idMU);
    printf("position : %d %d\n", Mu->position[0], Mu->position[1]);
    while (i <= 11)
    {

        printf("%c: %d %d\n", Mu->ADN[i][0], Mu->ADN[i][1], Mu->ADN[i][2]);
        i++;
    }
    i = 0;
    while (i <= 11)
    {
        printf("Capacity %c : %d\n", Mu->ADN[i][0], Mu->capacity[i]);
        i++;
    }

    printf("Life Points : %d\n", Mu->lifePoints);
    printf("speed : %d\n", Mu->speed);
    printf("status : %d\n", Mu->status);
    printf("Languor : %d\n", Mu->languor);
    i = 0;
    while (Mu->children[i] != 0)
    {
        printf("Children %d : %d\n", i, Mu->children[i++]);
    }
}