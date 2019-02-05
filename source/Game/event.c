#include "../../proto/supervisor.h"

void checkEvent()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_WINDOWEVENT:                                // Événement de la fenêtre
            if (event.window.event == SDL_WINDOWEVENT_CLOSE) // Fermeture de la fenêtre
            {
                // Action à faire lorsque l'utilisateur clique sur la croix
            }
            break;
        case SDL_KEYUP:                              // Événement de relâchement d'une touche clavier
            if (event.key.keysym.sym == SDLK_ESCAPE) // C'est la touche Échap
            {
                // Action à faire lorsque l'utilisateur relâche la touche Échap
            }
            break;
        }
    }
}
