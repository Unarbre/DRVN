#include "supervisor.h"

// Eugenism functions
tiny *fetchBestDna();
tiny *eugenism(int multiversSelection);
tiny *orderBestDna(struct GhostMu **ghosts);
tiny *bestDnaEver(int multivers, tiny **multiversBestDNA);

//GhostMu Functions
struct GhostMu *initiateGhostMu();
void freeGhost(struct GhostMu *ghost);
void freeGhosts(struct GhostMu **ghosts);
