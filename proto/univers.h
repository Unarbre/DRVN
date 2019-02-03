#include "supervisor.h"

// Define macro Struct to contain Univers' Parameters
struct Univers
{
    int version;
    int lastChildId;
    int age;
    int perenity;
    struct Population *population;
    struct Land *land;
    struct GraphData *graphData;
};

void initiateUnivers(struct Univers *univers, int version, int lastChildId, struct Population *population, struct Land *land);