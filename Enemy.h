#ifndef ENEMY_H
#define ENEMY_H

#include "gameobject.h"

class Game;  // Forward declaration

class Enemy : public GameObject {
public:
    Enemy(const char* texturesheet, int x, int y, Game* game);  // Constructor declaration
    ~Enemy() {}

    void update(GameObject* player);  // Override the update function

private:
    Game* game;  // Pointer to the Game instance
};

#endif  // ENEMY_H

