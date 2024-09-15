#include "gameobject.h"
#include "texture_manager.h"

GameObject::GameObject(const char* texturesheet, int x_1, int y_1)
    : xpos(x_1), ypos(y_1)// Use member initializer list
{
    objTexture = TextureManager::LoadTexture(texturesheet);
    srcRect.h = 600;
    srcRect.w = 600;
    srcRect.x = 0;
    srcRect.y = 0;
    destRect.w = 60;
    destRect.h = 60 ;
}

GameObject::~GameObject() {
    SDL_DestroyTexture(objTexture);
}

void GameObject::update() {
    const Uint8* keystates = SDL_GetKeyboardState(NULL);

    // Handle arrow key input for player movement
    if (keystates[SDL_SCANCODE_UP]) {
        ypos -= 1;  // Move up
    }
    if (keystates[SDL_SCANCODE_DOWN]) {
        ypos += 1;  // Move down
    }
    if (keystates[SDL_SCANCODE_LEFT]) {
        xpos -= 1;  // Move left
    }
    if (keystates[SDL_SCANCODE_RIGHT]) {
        xpos += 1;  // Move right
    }

    // Update player's position
    destRect.x = xpos;
    destRect.y = ypos;
}

void GameObject::Render() {
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
