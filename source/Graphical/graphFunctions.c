#include "../../proto/supervisor.h"

int graphGenerateWorld(struct Univers *univers)
{
    int i, j;
    int pX = 0, pY = 0;
    struct GraphData *graphData = malloc(sizeof(struct GraphData));

    univers->graphData = graphData;
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
            graphData->pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED); // Création d'un SDL_Renderer utilisant l'accélération matérielle
            if (graphData->pRenderer)
            {
                graphData->sTile = SDL_LoadBMP("assets/ground.bmp");
                graphData->sMu = SDL_LoadBMP("assets/mu.bmp");
                if (graphData->sTile && graphData->sMu)
                {
                    graphData->TileTexture = SDL_CreateTextureFromSurface(graphData->pRenderer, graphData->sTile); // Préparation du sprite
                    graphData->MuTexture = SDL_CreateTextureFromSurface(graphData->pRenderer, graphData->sMu);     // Préparation du sprite

                    if (graphData->TileTexture && graphData->MuTexture)
                    {
                        for (i = 0; i < univers->land->size; i++)
                        {
                            pX = 0;
                            for (j = 0; j < univers->land->size; j++)
                            {
                                SDL_Rect dest = {pX, pY, TSIZE, TSIZE};
                                SDL_RenderCopy(graphData->pRenderer, graphData->TileTexture, NULL, &dest); // Copie du sprite grâce au SDL_Renderer
                                if (univers->land->tiles[i][j].Mu != NULL)
                                {
                                    SDL_Rect dest2 = {pX, pY, TSIZE, TSIZE};
                                    SDL_RenderCopy(graphData->pRenderer, graphData->MuTexture, NULL, &dest2); // Copie du sprite grâce au SDL_Renderer
                                }
                                pX += TSIZE;
                            }
                            pY += TSIZE;
                        }
                        SDL_RenderPresent(graphData->pRenderer); // Affichage
                        SDL_Delay(2000);              /* Attendre cinq secondes, que l'utilisateur voit la fenêtre */
                    }
                    else
                    {
                        fprintf(stdout, "Échec de création de la texture (%s)\n", SDL_GetError());
                    }
                }
                else
                {
                    fprintf(stdout, "Échec de chargement du sprite (%s)\n", SDL_GetError());
                }
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