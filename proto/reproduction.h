#include "supervisor.h"

int reproduction(struct Univers *univers);
// Functions determining potentiel Sex partener
struct MU **checkClosePartner(struct Univers *univers, struct MU *currentMu, int *partnerAmount);
struct MU **orderedSexPartner(struct MU **SexPartner, int numPartner);
struct MU **orderSexAppeal(struct MU **sexPartner, int numPartner);
int tryBreed(struct MU *mu);
int luckBreedTest(int round);

// Functions realizing baby's conception
void breed(struct MU *dad, struct MU *mom, struct Univers *univers);
void shareDNA(struct MU *baby, struct MU *dad, struct MU *mom);
void affectChildren(int idChildren, struct MU *parent);
struct MU *insertChild(struct MU *child, struct Univers *univers);
int checkAffectPosition(struct MU *parent, struct MU **child, struct Univers *univers);

void freeBreedPartner(struct MU **sexPartners, int numPartner);