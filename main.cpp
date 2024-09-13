#include <SDL.h>
#include <iostream>

/*
compile: g++ -o sdl_game main.cpp -I/opt/homebrew/include/SDL2 -L/opt/homebrew/lib -lSDL2
run: ./sdl_game
*/

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("My SDL Game",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);
    SDL_Surface* screenSurface = SDL_GetWindowSurface(window);

    // Rectangle properties
    SDL_Rect rect = {100, 100, 50, 50};  // x, y, width, height
    int speed = 5;

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        // Handle events
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Keyboard input for moving the rectangle
        const Uint8* keystate = SDL_GetKeyboardState(nullptr);
        if (keystate[SDL_SCANCODE_UP]) {
            rect.y -= speed;
        }
        if (keystate[SDL_SCANCODE_DOWN]) {
            rect.y += speed;
        }
        if (keystate[SDL_SCANCODE_LEFT]) {
            rect.x -= speed;
        }
        if (keystate[SDL_SCANCODE_RIGHT]) {
            rect.x += speed;
        }

        // Clear screen
        SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));
        // Render the rectangle
        SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x00));
        // Update the window
        SDL_UpdateWindowSurface(window);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}