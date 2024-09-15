#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class Game {
public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    static SDL_Renderer* renderer;

    bool running() { return isRunning; }
    bool isRunning;

private:
    int count=0;
    
    SDL_Window *window;
    
};

#endif  // GAME_H
