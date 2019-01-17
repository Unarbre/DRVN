#include "../../proto/supervisor.h"

int movement(struct Univers *univers, struct Population *population, struct Land *land, struct MU *currentMu)
{
    int surrounding, i;
    currentMu = univers->population->startPopulation;
    for ( i = 0; i < population->density; i++)
    {
        printf("\n idMu : %d  ", currentMu->idMu);
        printf(" position %d  ", currentMu->position[0]);
        printf(" %d ", currentMu->position[1]);
        if(!canMove(currentMu))
        {
            if(1)//currentMu->status == 0)
                moveToSurvive(currentMu, land);
            surrounding = searchSurrounding(currentMu, land);
            // else if(surrounding < 0)
                printf("errorSurrounding\n");
            // else if(surrounding == 1)
        //         moveToBreed();
        //     else 
        //         moveToSearch();
        }
        printf(" new position %d ", currentMu->position[0]);
        printf(" %d  ", currentMu->position[1]);
        currentMu = currentMu->next;
    }
    return 0;
}

// move to breed

    // shearch if Mu are in range to breed (tiles + 2)
int searchSurrounding(struct MU * currentMu, struct Land *land)
{
    // if there is Mu in direct range
    return directRange(currentMu, land);

    // if there is no Mu in direct range but one in indirect
    return 1;

    // if there is no Mu at all
    return 2;

}

        //check if there is one in idrect range
int directRange(struct MU * currentMu, struct Land *land)
{
    int i, j;
    int x = currentMu->position[0];
    int y = currentMu->position[1];

    for(i = x - 1; i < x + 2; i++)
    {
        for(j = y - 1; j < y + 2;j++)
        {
            if(!checkIsntMu(i, j, land) && !(x == i && y ==j))
            {
                
                return 0;
            }
        }
    }
    return -1;
} 


    // move to breedable mu
int moveToBreed(struct MU * currentMu, struct Land *land)
{
    return 0;
}

    // move to search breedable Mu
int moveToSearch(struct MU * currentMu, struct Land *land)
{
    return 0;
}

int MoveLogic(struct MU * currentMu, struct Land *land)
{
    int i, j;
    int x = currentMu->position[0];
    int y = currentMu->position[1];
    for(i = x - 1; i < x + 2; i++)
    {
        for(j = y - 1; j < y + 2;j++)
        {
            if(!checkInLand(i, j, land) && !checkIsntMu(i, j, land) && !(x == i && y ==j))
            {
                land->tiles[currentMu->position[0]][currentMu->position[1]].Mu = NULL;
                currentMu->position[0] = i;
                currentMu->position[1] = j;
                land->tiles[currentMu->position[0]][currentMu->position[1]].Mu = currentMu;
                return 0;
            }
        }
    }
    // couldn't move
    return 1;
}

int checkIsntMu(int x, int y, struct Land *land)
{
    if(land->tiles[x][y].Mu == NULL){
        printf(" noMu ");
        return 0;
    }
    return 1;
}

int checkInLand(int x, int y, struct Land *land)
{
    if(x < land->size && x >= 0 && y < land->size && y >= 0)
        return 0;
    // if coordinates isn't in land
    return 1;
}

// check if Mu can move TEMPORARY : always can
int canMove(struct MU * currentMu)
{
    // if it can move
    return 0;
    //if it can't
    return 1;
}

// move to survive -> search a greater place

int moveToSurvive(struct MU * currentMu, struct Land *land)
{
    
    return MoveLogic(currentMu, land);
}
