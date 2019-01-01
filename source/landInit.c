#include "../proto/supervisor.h"

//LAND INITIALISATION

//  Initialise Land's parameters

void initiateLand(struct Land *land, int square)
{
    land->size = square;
    land->pressures = initialisePressures();
    land->tiles = initiateTiles(land->size, land->pressures);
}

// Initialise natural pressure on the Land
tiny *initialisePressures()
{
    int i;
    tiny *pressures = malloc(sizeof(tiny) * 8);
    for (i = 0; i < 8; i++)
    {
        pressures[i] = (rand() % 10) + 3;
        printf("%d\n", pressures[i]);
    }
    return pressures;
}

// Initialize each tiles.
tiny ***initiateTiles(int square, tiny *naturePressures)
{
    tiny ***tiles;
    tiny ***pressureForms = generatePressureForms(square);
    int i, j;

    tiles = affectTilesPressures(square, naturePressures, pressureForms);
    freePressureForms(pressureForms);
    return tiles;
}

// Generating arrays of pressure. First size is pressure ID (8 pressures), second size is
// all four peaks of the generated square, third size is coordonate of those peaks
tiny ***generatePressureForms(int square)
{
    int i, j;
    // TEMPORARY -> Number of pressures has been arbitrary choiced
    tiny ***pressureForms = malloc(sizeof(tiny **) * 8);

    for (i = 0; i < 8; i++)
    {
        pressureForms[i] = generatePressurePeaks(square);
        for (j = 0; j < 4; j++)
        {
            printf("pression %d, peak %d : %d %d\n", i, j, pressureForms[i][j][0], pressureForms[i][j][1]);
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

    // Generate distance between two peak to calculate square
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

// Return an array of square X square X pressures size, filled with all pressures value affected to tiles.
tiny ***affectTilesPressures(int square, tiny *naturePressures, tiny ***pressureForms)
{
    int i, j, k;
    tiny *geoPressures = initiateGeoPressures();
    tiny ***tiles = malloc(sizeof(tiny **) * square);
    for (i = 0; i < 50; i++)
    {
        tiles[i] = malloc(sizeof(tiny *) * square);
        for (j = 0; j < 50; j++)
        {
            //TEMPORARY -> 8 is the arbitrary choiced number of pressures. It may be changed
            tiles[i][j] = malloc(sizeof(tiny) * 8);
            for (k = 0; k < 8; k++)
            {
                tiles[i][j][k] = naturePressures[k];
                tiles[i][j][k] += pOnTile(pressureForms[k], geoPressures[k], i, j);
            }
        }
    }

    if (geoPressures != NULL)
        free(geoPressures);

    for (int i = 0; i < 8; i++)
        printf("pression %d : %d\n", i, tiles[0][0][i]);

    return tiles;
}

tiny *initiateGeoPressures()
{
    tiny *geoPressures = malloc(sizeof(tiny) * 8);
    int i;
    for (i = 0; i < 8; i++)
    {
        geoPressures[i] = (rand() % 59);
    }
    return geoPressures;
}

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

int isOnSquare(tiny **peaks, int firstPeak, int edge, int x, int y)
{
    if (x == 35 && y == 20)
    {
        for (int i = 0; i < 4; i++)
        {
            printf("peak %d : %d %d", i, peaks[i][0], peaks[i][1]);
        }
        printf("firstPeak: %d\n", firstPeak);
    }
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

// Return the topper left Peaks
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