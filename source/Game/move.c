#include "../../proto/supervisor.h"

int movement(struct Univers *univers)
{
    int surrounding;
    struct MU * currentMu = univers->population->startPopulation;
    
    while(currentMu->next != NULL)
    {
        if(canMove(currentMu))
        {
            surrounding = searchSurrounding(currentMu, univers->land);
            // printf("\n idMu : %d  ", currentMu->idMu);
            // printf("position : %d %d   ", currentMu->position[0], currentMu->position[1]);
            // if it's in dying state, mofe to a safer place
            if(currentMu->status == 0)
                moveToSurvive(currentMu, univers->land);
            else if(surrounding == 1){}
                //don't need to move
            // move to the mu it detected
            else if(surrounding == 2)
                moveToBreed(currentMu, univers->land);
            //move in a random possible position around him
            else 
                moveAlea(currentMu, univers->land);
        }
        // printf(" new position : %d ", currentMu->position[0]);
        // printf(" %d  ", currentMu->position[1]);
        // printf(" surrounding : %d ", surrounding);
        currentMu = currentMu->next;
    }
    return 1;
}


// move to breed

    // move to breedable mu
int moveToBreed(struct MU * currentMu, struct Land *land)
{
    int i, j;
    int x = currentMu->position[0];
    int y = currentMu->position[1];

    for(i = x - 2; i < x + 3; i++)
    {
        for(j = y - 2; j < y + 3;j++)
        {
            if(!(x == i && y ==j) && checkInLand(i, j, land) && !checkIsntMu(i, j, land) && directRange(currentMu, land))
            {
                land->tiles[currentMu->position[0]][currentMu->position[1]].Mu = NULL;
                currentMu->position[0] = x > 0 ? x - 1 : x + 1;
                currentMu->position[1] = y > 0 ? y - 1 : y + 1;
                land->tiles[currentMu->position[0]][currentMu->position[1]].Mu = currentMu;
                return 1;
            }
        }
    }
    return 0;
}

    // move to a random position
int moveAlea(struct MU * currentMu, struct Land *land)
{
    int i, j, count, random;
    int x = currentMu->position[0];
    int y = currentMu->position[1];
    int array[8][2] = {0};

    count =0;
    for(i = x - 1; i < x + 2; i++)
    {
        for(j = y - 1; j < y + 2;j++)
        {
            // save the possibles positions takeable
            if(!(x == i && y ==j) && checkInLand(i, j, land) && checkIsntMu(i, j, land))
            {
                array[count][0] = i;
                array[count][1] = j;
                count++;
            }
        }
    }
// take an alea value in the pool of possible value
    count = 0;
    do
    {
        random = rand() % 7;
        count++;
    } while(array[random][0] && count < 100);

    if(count != 99)
    {
        land->tiles[currentMu->position[0]][currentMu->position[1]].Mu = NULL;
        currentMu->position[0] = array[random][0];
        currentMu->position[1] = array[random][1];
        land->tiles[currentMu->position[0]][currentMu->position[1]].Mu = currentMu;
        return 1;
    }
    // couldn't move
    return 0;
}

    // shearch if Mu are in range to breed (tiles + 2)
int searchSurrounding(struct MU * currentMu, struct Land *land)
{
    // if there is Mu in direct range
    if(directRange(currentMu, land))
        return 1;

    // if there is no Mu in direct range but one in indirect
    if(indirectRange(currentMu, land))
        return 2;

    // if there is no Mu at all
    return 0;

}

// move startig from the top left to the bottom right
int MoveLogic(struct MU * currentMu, struct Land *land)
{
    int i, j;
    int x = currentMu->position[0];
    int y = currentMu->position[1];
    for(i = x - 1; i < x + 2; i++)
    {
        for(j = y - 1; j < y + 2;j++)
        {
            if(!(x == i && y ==j) && checkInLand(i, j, land) && checkIsntMu(i, j, land))
            {
                land->tiles[currentMu->position[0]][currentMu->position[1]].Mu = NULL;
                currentMu->position[0] = i;
                currentMu->position[1] = j;
                land->tiles[currentMu->position[0]][currentMu->position[1]].Mu = currentMu;
                return 1;
            }
        }
    }
    // couldn't move
    return 0;
}

int checkIsntMu(int x, int y, struct Land *land)
{
    if(land->tiles[x][y].Mu == NULL)
        return 1;
    return 0;
}

int checkInLand(int x, int y, struct Land *land)
{
    if(x < land->size && x >= 0 && y < land->size && y >= 0)
        return 1;
    // if coordinates isn't in land
    return 0;
}

// check if Mu can move TEMPORARY : always can
int canMove(struct MU * currentMu)
{
    // if it can move
    return 1;
    //if it can't
    return 0;
}

// move to survive -> search a greater place

int moveToSurvive(struct MU * currentMu, struct Land *land)
{
    return moveToSafestPlace(land, currentMu);
}

// search around Mu the best position to take 
int moveToSafestPlace(struct Land *land, struct MU *currentMu)
{
    int i, j, bx, by;
    int x = currentMu->position[0];
    int y = currentMu->position[1];
    int *capacityMu = currentMu->capacity;
    int average, averageMax = resistance(land, capacityMu, x, y);
    
    bx = x;
    by = y;
    for(i = x - 1; i < x + 2; i++)
    {
        for(j = y - 1; j < y + 2;j++)
        {
            if(checkInLand(i, j, land) && checkIsntMu(i, j, land) && !(x == i && y ==j))
            {
                average = resistance(land, capacityMu, i, j);
                // register the best position possible in averageMax, excluding critical value
                if(average > averageMax && average != 4242)
                {
                    averageMax = average;
                    bx = i;
                    by =j;
                }
            }
        }
    }
    land->tiles[currentMu->position[0]][currentMu->position[1]].Mu = NULL;
    currentMu->position[0] = bx;
    currentMu->position[1] = by;
    land->tiles[currentMu->position[0]][currentMu->position[1]].Mu = currentMu;
    return 0;
}

        // //check if there is at least one in direct range

int indirectRange(struct MU * currentMu, struct Land *land)
{
    int i, j;
    int x = currentMu->position[0];
    int y = currentMu->position[1];

    for(i = x - 2; i < x + 3; i++)
    {
        for(j = y - 2; j < y + 3;j++)
        {
            if(!(x == i && y ==j) && checkInLand(i, j, land) && !checkIsntMu(i, j, land))
            {
                return 1;
            }
        }
    }
    return 0;
}

        //check if there is at least one in direct range
int directRange(struct MU * currentMu, struct Land *land)
{
    int i, j;
    int x = currentMu->position[0];
    int y = currentMu->position[1];

    for(i = x - 1; i < x + 2; i++)
    {
        for(j = y - 1; j < y + 2;j++)
        {
            if(!(x == i && y ==j) && checkInLand(i, j, land) && !checkIsntMu(i, j, land))
            {
                return 1;
            }
        }
    }
    return 0;
} 