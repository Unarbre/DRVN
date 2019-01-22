#include "supervisor.h"

// loop.c
int startGame(struct Univers *univers);


// survival.c
int survival(struct Univers *univers, struct MU *currentMu);
    int changePv(struct Univers *univers, struct MU ** PcurrentMu);
    int testStatus(struct Land *land, struct MU ** currentMu);
        int resistance(struct Land *land, int *capacityMu, int x, int y);

// move.c
int movement(struct Univers *univers, struct MU *currentMu);
    int canMove(struct MU * currentMu);
    int moveToSurvive(struct MU * currentMu, struct Land *land);
        int moveToSafestPlace(struct Land *land, struct MU *currentMu);
    int searchSurrounding(struct MU * currentMu, struct Land *land);
        int indirectRange(struct MU * currentMu, struct Land *land);
    int moveToBreed(struct MU * currentMu, struct Land *land);
    int moveAlea(struct MU * currentMu, struct Land *land);
    int directRange(struct MU * currentMu, struct Land *land);
    
    // basic use functions
    int MoveLogic(struct MU * currentMu, struct Land *land);
    int checkInLand(int x, int y, struct Land *land);
    int checkIsntMu(int x, int y, struct Land *land);