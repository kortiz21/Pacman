#include "pacman.h"
#include "gameWorld.h"

#ifndef COLLISION_H
#define COLLISION_H

class Collision {

public:
    Collision(Pacman &pacman, GameWorld &gameWorld);
    //void checkCollision();
    //void checkCollisionWithGhost();
    //void checkCollisionWithExit();
    //void checkCollisionWithFood();
    //void checkCollisionWithPowerUp();
    bool checkCollisionWithWall(Pacman &pacman, GameWorld &gameWorld);
};

#endif