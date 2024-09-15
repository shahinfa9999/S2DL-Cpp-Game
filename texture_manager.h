#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "game.h"

class TextureManager{
    public:
        static SDL_Texture* LoadTexture (const char* filename);
        static void draw(SDL_Texture* text,SDL_Rect src, SDL_Rect dest);
};
#endif // TEXTURE_MANAGER_H