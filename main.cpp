#include "game.h"
/*
compile: g++ -o sdl_game main.cpp game.cpp -I/opt/homebrew/include/SDL2 -L/opt/homebrew/lib -lSDL2
g++ -std=c++11 -o sdl_game main.cpp game.cpp -I/opt/homebrew/include/SDL2 -L/opt/homebrew/lib -lSDL2 -lSDL2_image
g++ -std=c++11 -o sdl_game main.cpp game.cpp texture_manager.cpp -I/opt/homebrew/include/SDL2 -L/opt/homebrew/lib -lSDL2 -lSDL2_image


run: ./sdl_game
*/

Game *game=nullptr;

int main (int argc, const char * argv[])
{
    const int FPS = 60;
    const int FrameDelay = 1000/FPS;

    Uint32 framestart;
    int FrameTime;
    
    game = new Game();
    game ->init("trial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,800,600,false);
    while (game->running())
    {
        framestart = SDL_GetTicks();

        game->handleEvents();
        game->render();
        game->update();

        FrameTime = SDL_GetTicks() - framestart;

        if (FrameDelay > FrameTime)
        {
            SDL_Delay(FrameDelay-FrameTime);
        }
    }
    game->clean();
    return 0;
}