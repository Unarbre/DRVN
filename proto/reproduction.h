#include "supervisor.h"

int reproduction(struct Univers *univers);
struct MU **checkClosePartner(struct Univers *univers, struct MU *currentMu, int *partnerAmount);
struct MU **orderedSexPartner(struct MU **SexPartner, int numPartner);
struct MU **orderSexAppeal(struct MU **sexPartner, int numPartner);
void breed(struct MU *dad, struct MU *mom, struct Univers *univers);
void shareDNA(struct MU *baby, struct MU *dad, struct MU *mom);
void affectChildren(int idChildren, struct MU *parent);
void insertChild(struct MU **child, struct Univers *univers);
void freeBreedPartner(int numPartner, struct MU **sexPartners);
int tryBreed(struct MU *mu);
int luckBreedTest(int round);