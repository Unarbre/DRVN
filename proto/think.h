#include "supervisor.h"

struct Rules
{
    tiny *bestDna;
};

struct GhostMu
{
    int id;
    int **Dna;
    int goodDay;
    int born;
    int death;
};

// Initiate Rules Function
struct Rules *initiateRules();

// Think functions
tiny thinkDNA(int strand, tiny *bestDna);