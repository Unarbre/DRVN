/*
** Declaration of MU's structure
*/

// Define type for 1 Bytes numeric values
typedef unsigned char tiny;

struct MU
{
    int idMU;
    int status;
    int lifePoints;
    int speed;
    tiny **ADN;
    int *capacity;
    int *position;

    struct MU **children;
};

struct MU *procreate(int *population, int *lastChild, struct MU *Mus);
struct MU *addMU(struct MU *MUnivers, struct MU newMU, int *population);
struct MU *breed(struct MU *dad, struct MU *mom, int *id, int *population);
