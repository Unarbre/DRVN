#include "../../proto/supervisor.h"

int graphGenerateWorld(struct Univers *univers)
{
    int i, j;
    int pX = 0, pY = 0;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stdout, "Échec de l'initialisation de la SDL (%s)\n", SDL_GetError());
        return -1;
    }

    {
        // Window generation
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
                SDL_Surface *sTile = SDL_LoadBMP("assets/ground.bmp");
                SDL_Surface *sMu = SDL_LoadBMP("assets/mu.bmp");
                if (sTile && sMu)
                {
                    SDL_Texture *TileTexture = SDL_CreateTextureFromSurface(pRenderer, sTile); // Préparation du sprite
                    SDL_Texture *MuTexture = SDL_CreateTextureFromSurface(pRenderer, sMu); // Préparation du sprite

                    if (TileTexture && MuTexture)
                    {
                        for (i = 0; i < univers->population->density; i++)
                        {
                            pX = 0;
                            for (j = 0; j < univers->population->density; j++)
                            {
                                SDL_Rect dest = {pX, pY, TSIZE, TSIZE};
                                SDL_RenderCopy(pRenderer, TileTexture, NULL, &dest); // Copie du sprite grâce au SDL_Renderer
                                if (univers->land->tiles[i][j].Mu != NULL)
                                {
                                    SDL_Rect dest2 = {pX, pY, TSIZE, TSIZE};
                                    SDL_RenderCopy(pRenderer, MuTexture, NULL, &dest2); // Copie du sprite grâce au SDL_Renderer
                                }
                                pX += TSIZE;
                            }
                            pY += TSIZE;
                        }
                        SDL_RenderPresent(pRenderer); // Affichage
                        SDL_Delay(3000);              /* Attendre trois secondes, que l'utilisateur voit la fenêtre */

                        SDL_DestroyTexture(TileTexture); // Libération de la mémoire associée à la texture
                        SDL_DestroyTexture(MuTexture);
                    }
                    else
                    {
                        fprintf(stdout, "Échec de création de la texture (%s)\n", SDL_GetError());
                    }

                    SDL_FreeSurface(sTile); // Libération de la ressource occupée par le sprite
                    SDL_FreeSurface(sMu); // Libération de la ressource occupée par le sprite

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
    return 1;
}