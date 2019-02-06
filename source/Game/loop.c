#include "../../proto/supervisor.h"

// loop for the game
int startGame(struct Univers *univers)
{
    struct MU *currentMu;
    int loop = 1;

    currentMu = univers->population->startPopulation;
    for (int i = 0; i < univers->population->density; i++)
    {
        currentMu = currentMu->next;
    }

    while (loop && (univers->age < 50 && univers->population->startPopulation != NULL))
    {
// Reinitialize MUs Languor
        languorTime(univers);
//move Mu
        movement(univers);
        reproduction(univers);

// change status and lifePoints of each Mu
        survival(univers);
//kill Mu who need to be killed
        death(univers);
        univers->age += 1;

        graphFillWorld(univers);
//events
        if(loopEvent(univers) == 0)
            return 0;
        SDL_Delay(500);
    }
    endSimulation(univers);
    return 0;
}

int loopEvent(struct Univers *univers)
{
    int wait = 1;
    int breakSim = 1;
    SDL_Event eventSim;
    
    if(wait == 1)
    {
        SDL_FlushEvent(SDL_WINDOWEVENT_CLOSE);
        SDL_FlushEvent(SDL_SCANCODE_ESCAPE);
        SDL_PumpEvents();
        SDL_PollEvent(&eventSim);
        {
            const Uint8* pKeyStates = SDL_GetKeyboardState(NULL);

            if ( pKeyStates[SDL_SCANCODE_ESCAPE] || eventSim.window.event == SDL_WINDOWEVENT_CLOSE)
            {
                wait = 0;
            }
            if ( pKeyStates[SDL_SCANCODE_P] )
            {
                wait = 2;
                printPause(univers->graphData);
                while(breakSim == 1)
                {
                    SDL_FlushEvent(SDL_WINDOWEVENT_CLOSE);
                    SDL_FlushEvent(SDL_SCANCODE_ESCAPE);
                    SDL_PumpEvents();
                    SDL_PollEvent(&eventSim);
                    const Uint8* pKeyStatesBreak = SDL_GetKeyboardState(NULL);
                    if ( pKeyStates[SDL_SCANCODE_ESCAPE] || eventSim.window.event == SDL_WINDOWEVENT_CLOSE)
                    {
                        return 0;
                    }
                    if ( pKeyStatesBreak[SDL_SCANCODE_S] )
                    {
                        breakSim = 0;
                    }
                }
            }
        }
    }
    return wait;
}

void languorTime(struct Univers *univers)
{
    struct MU *startPopulation = univers->population->startPopulation;
    while (startPopulation != NULL)
    {
        startPopulation->languor = 0;
        startPopulation = startPopulation->next;
    }
}

int endSimulation(struct Univers *univers)
{
    int wait = 1;
    SDL_Event eventSim;

    printEndSimulation(univers->graphData);
    while(wait == 1)
    {
        SDL_FlushEvent(SDL_WINDOWEVENT_CLOSE);
        SDL_FlushEvent(SDL_SCANCODE_ESCAPE);
        SDL_PumpEvents();
        SDL_PollEvent(&eventSim);
        {
            const Uint8* pKeyStates = SDL_GetKeyboardState(NULL);
            if ( pKeyStates[SDL_SCANCODE_ESCAPE] || eventSim.window.event == SDL_WINDOWEVENT_CLOSE)
            {
                wait = 0;
            }
        }
    }
    return wait;
}