#include "../proto/supervisor.h"

int main(int argc, char **argv)
{
    int wait = 1;
    const Uint8* pKeyStates = SDL_GetKeyboardState(NULL);
    SDL_Event event;

    graphGenerateMenu();
    while(wait != 0)
    {
        // SDL_Delay(1000);
        SDL_FlushEvent(SDL_WINDOWEVENT_CLOSE);
        SDL_FlushEvent(SDL_SCANCODE_ESCAPE);
        SDL_PumpEvents();
        SDL_PollEvent(&event);
        {
            // quit
            if ( pKeyStates[SDL_SCANCODE_ESCAPE] || event.window.event == SDL_WINDOWEVENT_CLOSE)
            {
                wait = 0;
            }
            // start simulation
            if(pKeyStates[SDL_SCANCODE_RETURN])
            {
                wait = simulation();
            }
        }
        fprintf(stdout, "\n");
    }
    SDL_Quit();
    return wait;
}

int simulation()
{
    srand(time(NULL));

    struct Univers *univers = malloc(sizeof(struct Univers));
    int idMu = 1;
    struct Population *population;
    struct Land land;
    // Size is modulable
    int size = 15;

    // GENERATION OF UNIVERS    
    initiateLand(&land, size);
    population = initiatePopulation(&land, 11, &idMu, size);
    initiateUnivers(univers, idMu, population, &land);
    graphGenerateWorld(univers);

    printf("play\n");
    startGame(univers);
    freeUnivers(univers);
    return 42;
}

