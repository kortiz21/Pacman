#include <SFML/Graphics.hpp>
#include "gameTile.h"
#include <vector>

#ifndef GAMEWORLD_H
#define GAMEWORLD_H

class GameWorld {
    // the position of the exit
    sf::Vector2i exitPos;
    // the position of the player
    sf::Vector2i playerPos;
    // the positions of the ghosts
    std::vector<sf::Vector2i> ghostPos;
    // reset the entire map to its initial state
    void setUpInitialState();
    // set up enemy positions
    void setUpEnemyPositions();
    // setup the tiles
    void setUpTiles();
public:
    // two dimensional vector of tiles
    std::vector<std::vector<GameTile *>> tiles;
    // the length of the grid
    int gridLength;
    // constructor
    GameWorld();
};

#endif