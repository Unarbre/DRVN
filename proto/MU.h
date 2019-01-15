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
    // Mu's speed, determining the order of Mu's actions in turn
    int speed;
    // "Boolean" determining if Mu can procreate or note
    int languor;
    // Turn when Mu has been generated
    int birthDate;
    // ADN of MU, in format [X] [tiny] [tiny]
    tiny **ADN;
    // Interpretation of ADN
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
void shareADN(struct MU *baby, struct MU *dad, struct MU *mom);
struct MU *addMU(struct MU *MUnivers, struct MU newMU, int *population);
struct MU *breed(struct MU *dad, struct MU *mom, int *id, int *population);
void affectChildren(int idChildren, struct MU *parent);