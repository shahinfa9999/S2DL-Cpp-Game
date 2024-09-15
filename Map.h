#ifndef MAP_H
#define MAP_H

#include <SDL.h>
#include "texture_manager.h"

class Map {
public:
    Map();
    void LoadMap(int arr[20][25]);
    void DrawMap();
    bool isWaterTile(int x, int y);  // Method to check if a tile is water

private:
    int map[20][25];
    SDL_Texture *dirt;
    SDL_Texture *water;
    SDL_Texture *grass;
    SDL_Rect src, dest;
};

#endif // MAP_H