#include "gameobject.h"
#include "texture_manager.h"

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren, int x_1, int y_1)
    : xpos(x_1), ypos(y_1), renderer(ren) // Use member initializer list
{
    objTexture = TextureManager::LoadTexture(texturesheet, ren);
    srcRect.h = 600;
    srcRect.w = 600;
    srcRect.x = 0;
    srcRect.y = 0;
    destRect.w = srcRect.w/10;
    destRect.h = srcRect.h/10 ;
}

GameObject::~GameObject() {
    SDL_DestroyTexture(objTexture);
}

void GameObject::update() {
    xpos++;
    ypos++;

    destRect.x = xpos;
    destRect.y = ypos;
}

void GameObject::Render() {
    SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}
