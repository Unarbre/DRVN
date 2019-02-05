#include "supervisor.h"

struct Rules
{
    tiny *bestDna;
};

struct Rules *initiateRules();

// Eugenism functions
tiny *fetchBestDna();
tiny *eugenism(int multiversSlection);