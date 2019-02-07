#include "../../proto/supervisor.h"

void initiateUnivers(struct Univers *univers, int lastChildId, struct Population *population, struct Land *land)
{

    univers->version = getVersion();
    univers->lastChildId = lastChildId;
    univers->age = 0;
    univers->perenity = 100;
    // Generate a string symbolizing the path to the univers memory File
    univers->universFilePath = createUniversFile(univers->version);
    univers->land = land;

    univers->population = population;

    univers->rules = initiateRules();
    // Create the file so next include may be in "a" mode, facilitating its use
    FILE *fileCreator = fopen(univers->universFilePath, "w");
    fclose(fileCreator);
}

char *createUniversFile(int version)
{
    char *fileName = malloc(sizeof(char) * 50);
    strcpy(fileName, "UniversData/version");
    char *universVersion = malloc(sizeof(char) * 3);
    SDL_itoa(version, universVersion, 10);
    strcat(fileName, universVersion);
    free(universVersion);
    return fileName;
}

int getVersion()
{
    int count = 1;
    DIR *dirp;
    struct dirent *dir;
    dirp = opendir("./UniversData");
    while ((dir = readdir(dirp)) != NULL)
    {
        if (dir->d_type == DT_REG)
            count++;
    }
    closedir(dirp);
    return count;
}