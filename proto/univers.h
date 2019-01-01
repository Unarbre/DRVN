#include "supervisor.h"

// Define macro Struct to contain Univers' Parameters
struct Univers
{
    int version;
    int lastChildId;
    int population;
    int age;
    int perenity;
    struct MU *MUs;
    struct Land *Land;
};

void initiateUnivers(struct Univers *univers, int version, int lastChildId, int population, struct MU *Mus, struct Land *land);