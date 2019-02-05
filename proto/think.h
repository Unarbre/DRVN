#include "supervisor.h"

struct Rules
{
    tiny *bestDna;
};

struct Rules *initiateRules();

// Eugenism functions
tiny *fetchBestDna();
tiny *foundFile(int multiversSelection);
tiny *eugenism(struct dirent *dir);