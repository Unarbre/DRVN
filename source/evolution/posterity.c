#include "../../proto/supervisor.h"


// PRint MU in the apppropriated FIle 
void toPosterity(struct MU *ghost, struct Univers *univers)
{
    int i, goodLife;
    FILE *fUni = fopen(univers->universFilePath, "a");
    fprintf(fUni, "%d", ghost->idMu);
    for (i = 0; i < 12; i++)
    {
        fprintf(fUni, " %c %d %d", ghost->DNA[i][0], ghost->DNA[i][1], ghost->DNA[i][2]);
    }
    goodLife = turnOfGoodLife(ghost->birthDate, univers->age, ghost->lifePoints);
    fprintf(fUni, " %d %d %d", goodLife, ghost->birthDate, univers->age);
    fputc('\n', fUni);
    fclose(fUni);
}

int turnOfGoodLife(int birthdate, int death, int lifePoints)
{
    int longevity = death - birthdate;
    return lifePoints - (lifePoints - longevity);
}