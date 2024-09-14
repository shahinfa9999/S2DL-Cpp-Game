#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "game.h"

class TextureManager{
    public:
        static SDL_Texture* LoadTexture (const char* filename, SDL_Renderer* ren);
};
#endif // TEXTURE_MANAGER_H