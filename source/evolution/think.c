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
            multiversBestDNA[i] = foundFile(i + 1);
        }
    }
    else
    {
        // TEmporary
        return NULL;
    }
    return NULL;
}

tiny *foundFile(int multiversSelection)
{
    int i;
    printf("%d\n", multiversSelection);
    tiny *bestDnas;
    DIR *dirp;
    struct dirent *dir;
    dirp = opendir("./UniversData");
    puts("ok ok");
    // to dodge the '.' file
    for (i = 0; i < 1 + multiversSelection; i++)
    {
        dir = readdir(dirp);
    }
    printf("%s\n", dir->d_name);
    bestDnas = eugenism(dir);
    //Temporary
    return NULL;
}

tiny *eugenism(struct dirent *dir)
{
    int goodMus[10] = {0};
    int i = 0;
    int goodDay = 50;
    tiny *bestAdns = malloc(sizeof(tiny) * 5);
    printf("%s", dir->d_name);
    FILE *fUni = fopen(dir->d_name, "r");
    if (fUni == NULL)
    {
        return NULL;
    }
    rewind(fUni);
    fscanf(fUni, "%d", &goodDay);
    printf("%d\n", goodDay);
    fseek(fUni, 112, SEEK_CUR);
    puts("in!");
    while (!feof(fUni) || i != 9)
    {
        fscanf(fUni, "%d", &goodDay);
        // printf("%d\n", goodDay);
        if (goodDay > 6)
        {
            fseek(fUni, -116, SEEK_CUR);
            fscanf(fUni, "%d", &(goodMus[i++]));
            fseek(fUni, 125 + 112, SEEK_CUR);
        }
        else
        {
            fseek(fUni, 125, SEEK_CUR);
        }
    }
    printf("%d\n", goodMus[11]);
    return NULL;
}