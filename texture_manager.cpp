#include "texture_manager.h"

SDL_Texture* TextureManager::LoadTexture(const char* filename)
{
    SDL_Surface* tempsurface = IMG_Load(filename);
    SDL_Texture* playertex = SDL_CreateTextureFromSurface(Game::renderer,tempsurface);
    SDL_FreeSurface(tempsurface);

    return playertex;
}
void TextureManager::draw(SDL_Texture* text,SDL_Rect src, SDL_Rect dest)
{
    SDL_RenderCopy(Game::renderer,text, &src, &dest);
}