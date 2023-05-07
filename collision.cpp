#include <iostream>

#include "Headers/collision.h"
#include "Headers/constants.h"
#include "Headers/pacman.h"
#include "Headers/gameWorld.h"

// Collision::Collision(Pacman &pacman, GameWorld &gameWorld) {
// }

bool Collision::checkCollisionWithWall(Pacman &pacman, GameWorld &gameWorld) {
    // checkCollision();
    if (pacman.getSprite().getGlobalBounds().intersects(gameWorld.tiles[pacman.getPosition().x][pacman.getPosition().y]->getSprite().getGlobalBounds())) {
        std::cout << "Collision detected!" << std::endl;
        return true;
    }
    return false;
}