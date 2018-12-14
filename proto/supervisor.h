#ifndef SUPERVISOR
#define SUPERVISOR

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include "MU.h"
#include "land.h"
#include "initialisation.h"
#include "memoryRelease.h"

// Define macro Struct to contain Univers' Parameters
struct Univers
{
    int version;
    struct MU **MUs;
    struct Land *Land;
};

// Unusual Assets
void printPopulation(struct MU *MUs, int population);
void printMu(struct MU *Mu);
#endif