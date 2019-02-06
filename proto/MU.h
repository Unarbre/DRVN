#include "supervisor.h"

/*
** Declaration of MU's structure
*/

struct MU
{
    // Mu's unique ID
    int idMu;
    // MU's status : 0 dying state, 1 neutral state, 2 lively state.
    int status;
    // MU's longevity and stamina
    int lifePoints;
    // Mu's sex attread
    int sexPreference;
    // "Boolean" determining if Mu can procreate or note
    int languor;
    // Turn when Mu has been generated
    int birthDate;
    // DNA of MU, in format [X] [tiny] [tiny]
    tiny **DNA;
    // Interpretation of DNA
    int *capacity;
    // Position of MU on map
    int *position;
    // Array of Mu's ID filled with children of Mu
    int *children;

    //pointer to next MU in array
    struct MU *next;
};

struct Population
{
    struct MU *startPopulation;
    
    // Amount on MU in the startPopulation chained list
    int density;
};
void procreateRound(struct Univers **univers);
struct MU *addMU(struct MU *MUnivers, struct MU newMU, int *population);
