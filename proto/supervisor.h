#ifndef SUPERVISOR
#define SUPERVISOR

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

// Define type for 1 Bytes numeric values before any custom include, so functions do recognize custom type
typedef unsigned char tiny;

#include "MU.h"
#include "land.h"
#include "populationInit.h"
#include "landInit.h"
#include "univers.h"
// Memory release HAS TO BE the last include, as it is the last thing to do, and receive specific elements from others .h (custom types)
#include "memoryRelease.h"

// Unusual Assets
void printPopulation(struct MU *MUs, int population);
void printMu(struct MU *Mu);
#endif