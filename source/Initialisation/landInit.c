#include "../../proto/supervisor.h"

//LAND INITIALISATION

//  Initialise Land's parameters

void initiateLand(struct Land * land, int square)
{
    int i, j;
    // Affect World Pressures unifom to all tiles
    land->worldPressure = initialisePressures();
    land->size = square;
    // Generate  8 zones where one particular pressure is enchanced
    tiny ***pressureForms = generatePressureForms(square);



    struct Tile **tiles = malloc(sizeof(struct Tile *) * square);
    for (i = 0; i < square ; i++)
    {
        tiles[i] = malloc(sizeof(struct Tile) * square);
        for (j = 0; j < square; j++)
        {
            tiles[i][j].x = i;
            tiles[i][j].y = j;
            // calculate pressures values depending on worldPressure and PressureForms
            tiles[i][j].pressures = affectPressure(pressureForms, land->worldPressure, i, j);
            tiles[i][j].Mu = NULL;
        }
    }

    freePressureForms(pressureForms);
    land->tiles = tiles;
}

// Return the 8 pressures applied on the passed Tile (by coordonates)
tiny *affectPressure(tiny ***pressureForms, tiny *worldPressures, int x, int y)
{
    int i;
    // calcule a pressure random in the forms
    tiny *geoPressure = initiateGeoPressures();
    // TEMPORARY  -> Number of 8 pressures is arbitrary
    tiny *pressures = malloc(sizeof(tiny) * 8);

    for (i = 0; i < 8; i++)
    {
        pressures[i] = worldPressures[i];
        pressures[i] += pOnTile(pressureForms[i], geoPressure[i], x, y);
    }
    free(geoPressure);
    return pressures;
}

// Initialise 8 naturals pressures applied on the whole Land
tiny *initialisePressures()
{
    int i;
    tiny *pressures = malloc(sizeof(tiny) * 8);
    for (i = 0; i < 8; i++)
    {
        // pressures value between 3 and 13
        pressures[i] = (rand() % 10) + 3;
    }
    return pressures;
}


// Generating 8 X 4 peaks symbolizing square of pressures. The returned array is : First size pressure ID (8 pressures), second size is
// all four peaks of the generated square, third size is coordonate of those peaks
tiny ***generatePressureForms(int square)
{
    int i, j;
    // TEMPORARY -> Number of pressures has been arbitrary choiced
    tiny ***pressureForms = malloc(sizeof(tiny **) * 8);

    for (i = 0; i < 8; i++)
    {
        //set the coordinates of 8 pressureForms
        pressureForms[i] = generatePressurePeaks(square);
        for (j = 0; j < 4; j++)
        {
            // printf("pression %d, peak %d : %d %d\n", i, j, pressureForms[i][j][0], pressureForms[i][j][1]);
        }
    }

    return pressureForms;
}

// Return an array of 4 peaks(filled with 2 points, for coordonate), in order to draw square
tiny **generatePressurePeaks(int square)
{

    int i, topBot, leftRight, edge;
    tiny **peaks = malloc(sizeof(tiny *) * 4);

    // First Tile must not be on the very ledge of the field
    peaks[0] = generateFirstPeak(square);

    // Generate distance between two peak to calculate square of pressure
    edge = generateEdge(square);
    topBot = guessTopBot(square, peaks[0], edge);
    peaks[1] = generateSecondPeak(peaks[0], edge, topBot);
    leftRight = guessLeftRight(square, peaks[0], edge);

    // Copy peaks on other side
    for (i = 2; i < 4; i++)
    {
        peaks[i] = generateVPeak(peaks[i - 2], edge, leftRight);
    }
    return peaks;
}

// Generate randomly the first peak
tiny *generateFirstPeak(int square)
{
    tiny *peak = malloc(sizeof(tiny) * 2);
    peak[0] = (rand() % (square - 3)) + 3;
    peak[1] = (rand() % (square - 3)) + 3;
    return peak;
}

// Generate second peak, from vertical direction and initial peak
tiny *generateSecondPeak(tiny *firstPeak, int edge, int TopBot)
{
    tiny *peak = malloc(sizeof(tiny) * 2);
    peak[0] = firstPeak[0];
    peak[1] = TopBot ? firstPeak[1] + edge : firstPeak[1] - edge;
    return peak;
}

// Generate peaks verticaly from other points
tiny *generateVPeak(tiny *initialePeak, int edge, int leftRight)
{
    tiny *peak = malloc(sizeof(tiny) * 2);
    peak[0] = leftRight ? initialePeak[0] + edge : initialePeak[0] - edge;
    peak[1] = initialePeak[1];
    return peak;
}

// return adapted size of pressure, depending of the land's size
int generateEdge(int square)
{
    return (square / 10) + (rand() % 5) + 2;
}

//  Decide the vertical direction of the square. 0 for top, 1 for bot.
int guessTopBot(int square, tiny *firstPeak, int edge)
{
    int topBot = rand() % 2;

    // Check if the pressure square will not cross out of the field
    if (topBot == 0)
    {
        return (firstPeak[1] - edge) >= 0 ? topBot : 1;
    }
    else
    {
        return (firstPeak[1] + edge) <= square ? topBot : 0;
    }
    printf("error: TopBot initialized wrong\n");
    return -1;
}

//  Decide the horizontal direction of the square. 0 for left, 1 for right.
int guessLeftRight(int square, tiny *firstPeak, int edge)
{
    int leftRight = rand() % 2;

    // Check if the pressure square will not cross out of the field
    if (leftRight == 0)
    {
        return (firstPeak[0] - edge) >= 0 ? leftRight : 1;
    }
    else
    {
        return (firstPeak[0] + edge) <= square ? leftRight : 0;
    }
    printf("error: rightLeft initialized wrong\n");
    return -1;
}

// Return the 8 local Pressure (value, not coordonates)
tiny *initiateGeoPressures()
{
    tiny *geoPressures = malloc(sizeof(tiny) * 8);
    int i;
    for (i = 0; i < 8; i++)
    {
        geoPressures[i] = (rand() % 59) + 10;
    }
    return geoPressures;
}

// Return 0 or the pressure applied by local singularity
tiny pOnTile(tiny **peaks, tiny pressure, int x, int y)
{
    int firstPeak = fPeaks(peaks);
    int edge = abs(peaks[0][0] - peaks[2][0]);
    if (isOnSquare(peaks, firstPeak, edge, x, y))
    {
        return pressure;
    }
    return 0;
}

// Check if Tile on the the pressure square
int isOnSquare(tiny **peaks, int firstPeak, int edge, int x, int y)
{
    // Check if X coordonate of tile is in Pressure square
    if (x > peaks[firstPeak][0] && x < (peaks[firstPeak][0] + edge))
    {
        if (y > peaks[firstPeak][1] && y < (peaks[firstPeak][1] + edge))
        {
            return 1;
        }
    }
    return 0;
}

// Return the topper left Peak
int fPeaks(tiny **peaks)
{
    if (peaks[0][0] < peaks[2][0])
    {
        if (peaks[0][1] < peaks[1][1])
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        if (peaks[2][1] < peaks[3][1])
        {
            return 2;
        }
        else
        {
            return 3;
        }
    }
    printf("Error, fpeaks went wrong");
    return -1;
}