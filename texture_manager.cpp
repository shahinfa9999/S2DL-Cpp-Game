#include "texture_manager.h"

SDL_Texture* TextureManager::LoadTexture(const char* filename, SDL_Renderer* ren)
{
    SDL_Surface* tempsurface = IMG_Load(filename);
    SDL_Texture* playertex = SDL_CreateTextureFromSurface(ren,tempsurface);
    SDL_FreeSurface(tempsurface);

    return playertex;
}