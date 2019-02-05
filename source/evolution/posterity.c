#include "../../proto/supervisor.h"

void toPosterity(struct MU *ghost, struct Univers *univers)
{
    int i;
    FILE *fUni = fopen(univers->universFilePath, "a");
    fprintf(fUni, "%d", ghost->idMu);
    for (i = 0; i < 12; i++)
    {
        fprintf(fUni, "%c%d%d", ghost->DNA[i][0], ghost->DNA[i][1], ghost->DNA[i][2]);
    }
    fprintf(fUni, "%d%d", ghost->birthDate, univers->age);
    fclose(fUni);
}