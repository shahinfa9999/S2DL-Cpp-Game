#include "game.h"
/*
compile: g++ -o sdl_game main.cpp game.cpp -I/opt/homebrew/include/SDL2 -L/opt/homebrew/lib -lSDL2
run: ./sdl_game
*/

Game *game=nullptr;

int main (int argc, const char * argv[])
{
    game = new Game();
    game ->init("trial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,800,600,false);
    while (game->running())
    {
        game->handleEvents();
        game->render();
        game->update();
    }
    game->clean();
    return 0;
}