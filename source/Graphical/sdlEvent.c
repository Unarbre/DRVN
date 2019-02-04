#include "../../proto/supervisor.h"

int sdlMenu()
{
    SDL_Event event;

    while ( SDL_PollEvent(&event) )
    {
        printf("paillons\n");
        switch(event.type)
        {
            case SDL_WINDOWEVENT:
                if ( event.window.event == SDL_WINDOWEVENT_CLOSE )
                {
                    return 0;
                }
                break;
            case SDL_KEYUP: 
                // if ( event.key.keysym.sym == SDLK_ESCAPE ) 
                // {
                //     return 0;
                // }
                break;
                if ( event.key.keysym.sym == SDLK_RETURN)
                {
                    return 2;
                }
        }
    }
    return 1;
}