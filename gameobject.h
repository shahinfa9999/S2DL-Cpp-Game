#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL.h>
#include "texture_manager.h"

class GameObject {
public:
    GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y);
    ~GameObject();

    void update();
    void Render();

private:
    int xpos;
    int ypos;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* renderer;
};

#endif // GAMEOBJECT_H
