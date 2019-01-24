#include "../proto/supervisor.h"

// papillon
int main(int argc, char **argv)
{
    srand(time(NULL));
    int idMu = 1;

    // Size is modulable
    int size = 20;

    // GENERATION OF UNIVERS
    struct Land land;
    initiateLand(&land, size);
    struct Population *population = initiatePopulation(&land, 10, &idMu, size);
    // printf("%d\n", population->startPopulation->idMu);
    initiateLand(&land, size);
    struct Population *population = initiatePopulation(&land, 10, &idMu, size);

    struct Univers *univers = malloc(sizeof(struct Univers));
    initiateUnivers(univers, 1, idMu, population, &land);
    
    if(!startGame(univers))
    {
            // printf("\n%d\n", univers->age);


    if (!startGame(univers, population, &land))
    {
        // printf("%d\n", univers->age);

        // printMu(population->startPopulation);
        // printTile(land.tiles[15][15]);
        freeUnivers(univers);

        // printf("outiout!");

        SDL_Quit();
        return 0;
    }
    return 1;
}