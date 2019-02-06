#include "../proto/supervisor.h"

/*
 * This function print an MU and all its caracteristics
*/
void printMu(struct MU *Mu)
{
    int i = 0;
    printf("\nId :%d\n", Mu->idMu);
    printf("position : %d %d\n", Mu->position[0], Mu->position[1]);
    while (i <= 11)
    {

        printf("%c: %d %d\n", Mu->DNA[i][0], Mu->DNA[i][1], Mu->DNA[i][2]);
        i++;
    }
    i = 0;
    while (i <= 11)
    {
        printf("Capacity %c : %d\n", Mu->DNA[i][0], Mu->capacity[i]);
        i++;
    }

    printf("Life Points : %d\n", Mu->lifePoints);
    printf("sex Preference : %d\n", Mu->sexPreference);
    printf("status : %d\n", Mu->status);
    printf("Languor : %d\n", Mu->languor);

    i = 0;
    // while (Mu->children[i] != -1)
    // {
    //     printf("Children %d : %d\n", i, Mu->children[i]);
    //     i++;
    // }
}

void printTile(struct Tile tile)
{
    int i;
    printf("Position : %d %d\n", tile.x, tile.y);
    for (i = 0; i < 8; i++)
    {
        printf("Pression %d: %d\n", i, tile.pressures[i]);
    }

    if (tile.Mu != NULL)
    {
        printMu(tile.Mu);
    }
}