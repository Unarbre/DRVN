#include "../../proto/supervisor.h"

void initiateUnivers(struct Univers *univers, int lastChildId, struct Population *population, struct Land *land)
{
    univers->version = 1;
    univers->lastChildId = lastChildId;
    univers->age = 0;
    univers->perenity = 100;
    univers->land = land;
    univers->population = population;
}

char *createUniversFile(int version)
{
    char *fileName = malloc(sizeof(char) * 13);
    char *universVersion = malloc(sizeof(char) * 3);
    SDL_itoa(version, universVersion, 10);
    printf("%s", universVersion);
    strcat(fileName, universVersion);
    printf("%s", fileName);
    return fileName;
}