/*
** Declaration of MU's structure
*/
struct MU
{
    int idMU;
    char **ADN;
    int **capacity;
    int *position;

    struct MU **children;
};

int checkPosition(int squareSize, int *position, struct MU *MUs, int population);
int *generatePosition(int squareSize, struct MU *MUs, int population);
void initiatePopulation(struct MU *MUs, int number, int *idMU, int squareSize, int population);
struct MU *addMU(struct MU *MUnivers, struct MU newMU, int *population);
void breed(struct MU *dad, struct MU *mom);