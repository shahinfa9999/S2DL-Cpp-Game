#include "Enemy.h"
#include "game.h"

Enemy::Enemy(const char* texturesheet, int x, int y, Game* game) : GameObject(texturesheet, x, y), game(game) {
    // Constructor implementation
}

void Enemy::update(GameObject* player) {
    // Calculate the direction towards the player
    int xDirection = player->xpos - xpos;
    int yDirection = player->ypos - ypos;

    // Normalize the direction vector
    if (xDirection != 0) {
        xDirection /= abs(xDirection);  // Move in the direction of the player (1 or -1)
    }
    if (yDirection != 0) {
        yDirection /= abs(yDirection);  // Move in the direction of the player (1 or -1)
    }

    // Move the enemy at 2x speed towards the player
    xpos += 1 * xDirection;
    ypos += 1 * yDirection;

    // Update enemy's position
    destRect.x = xpos;
    destRect.y = ypos;

    // Check for collision with player
    if (abs(xpos - player->xpos) < 32 && abs(ypos - player->ypos) < 32) {
        std::cout << "Enemy caught the player!" << std::endl;
        game->isRunning = false;  // End the game
    }
}
