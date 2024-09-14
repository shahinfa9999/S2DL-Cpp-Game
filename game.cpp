#include "game.h"

Game::Game() : window(nullptr), renderer(nullptr), isRunning(false)
{}

Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystem initialized" << std::endl;
        
        // Create window
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window)
        {
            std::cout << "Window created" << std::endl;
        }
        
        // Create renderer
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created" << std::endl;
        }
        
        isRunning = true;
    }
    else
    {
        isRunning = false;
    }
}

void Game::update()
{
    // Update game state here
}

void Game::render()
{
    SDL_RenderClear(renderer);   // Clear the renderer
    // Render game objects here
    SDL_RenderPresent(renderer); // Present the renderer
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);  // Correctly poll event with pointer
    
    switch (event.type)
    {
        case SDL_QUIT:  // Correct event type
            isRunning = false;
            break;
        
        default:
            break;
    }
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}
