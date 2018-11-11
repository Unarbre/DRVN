/*
** Declaration of MU's structure
*/
struct MU
{
    int pressure;
    int skin;
    int heat;
};

void initiatePopulation(struct MU *str, int number);
struct MU *addMU(struct MU *MUnivers, struct MU newMU, int *population);
void breed(struct MU *dad, struct MU *mom);