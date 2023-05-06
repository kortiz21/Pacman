#include <SFML/Graphics.hpp>
#include "gameTile.h"
#include "pacman.h"
#include <vector>
#include <string>

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
    void setUpInitialState(std::vector<std::string> &map, Pacman &pacman);
    // set up enemy positions
    void setUpEnemyPositions();
    // setup the tiles
    void setUpTiles(std::vector<std::string> &map, Pacman& pacman);
public:
    // two dimensional vector of tiles
    std::vector<std::vector<GameTile *>> tiles;
    // constructor
    GameWorld(std::vector<std::string> &map, Pacman &pacman);
};

#endif