#include "supervisor.h"

struct GraphData
{
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;

    SDL_Surface *sTile;
    SDL_Surface *sMu;

    SDL_Texture *TileTexture;
    SDL_Texture *MuTexture;
};

int graphGenerateWorld(struct Univers *univers);
    int graphFillWorld(struct Univers *univers);

int sdlMenu();
