/*
** Declaration of MU's structure
*/

// Define type for 1 Bytes numeric values
typedef unsigned char tiny;

struct MU
{
    int idMU;
    int lifePoints;
    tiny **ADN;
    int *capacity;
    int *position;

    struct MU **children;
};

int checkPosition(int squareSize, int *position, struct MU *MUs, int population);
struct MU *addMU(struct MU *MUnivers, struct MU newMU, int *population);
void breed(struct MU *dad, struct MU *mom, int *id, int * population);
void generateMu(struct MU *Mu, int *idMu, int population, int squareSize, struct MU *Mus);
int *generatePosition(int squareSize, struct MU *MUs, int population);
