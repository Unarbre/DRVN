#include "../../proto/supervisor.h"

int graphGenerateWorld(struct Univers *univers)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stdout, "Échec de l'initialisation de la SDL (%s)\n", SDL_GetError());
        return -1;
    }

    {
        //Création de la fenêtre
        SDL_Window *pWindow = SDL_CreateWindow("Don't Riot Versus Nature", SDL_WINDOWPOS_UNDEFINED,
                                               SDL_WINDOWPOS_UNDEFINED,
                                               640,
                                               480,
                                               SDL_WINDOW_FULLSCREEN_DESKTOP);

        if (pWindow)
        {
            SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED); // Création d'un SDL_Renderer utilisant l'accélération matérielle
            if (pRenderer)
            {
                SDL_Surface *pSprite = SDL_LoadBMP("./gw.bmp");
                if (pSprite)
                {
                    SDL_Texture *pTexture = SDL_CreateTextureFromSurface(pRenderer, pSprite); // Préparation du sprite
                    if (pTexture)
                    {
                        SDL_Rect dest = {640 / 2 - pSprite->w / 2, 480 / 2 - pSprite->h / 2, pSprite->w, pSprite->h};
                        SDL_RenderCopy(pRenderer, pTexture, NULL, &dest); // Copie du sprite grâce au SDL_Renderer
                        printf("ca y va !");
                        SDL_RenderPresent(pRenderer); // Affichage
                        SDL_Delay(3000);              /* Attendre trois secondes, que l'utilisateur voit la fenêtre */

                        SDL_DestroyTexture(pTexture); // Libération de la mémoire associée à la texture
                    }
                    else
                    {
                        fprintf(stdout, "Échec de création de la texture (%s)\n", SDL_GetError());
                    }

                    SDL_FreeSurface(pSprite); // Libération de la ressource occupée par le sprite
                }
                else
                {
                    fprintf(stdout, "Échec de chargement du sprite (%s)\n", SDL_GetError());
                }

                SDL_DestroyRenderer(pRenderer); // Libération de la mémoire du SDL_Renderer
            }
            else
            {
                fprintf(stdout, "Échec de création du renderer (%s)\n", SDL_GetError());
            }
        }
        else
        {
            fprintf(stderr, "Erreur de création de la fenêtre: %s\n", SDL_GetError());
        }
    }
}