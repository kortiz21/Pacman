#include <SFML/Graphics.hpp>
#include <string>

#ifndef GAMETILE_H
#define GAMETILE_H

class GameTile {
public:
    // the position of the tile if passable
    bool isPassable;
    // the position of the tile if exit
    bool isExit;
    // the position of the tile, contains x and y coordinates
    sf::Vector2f pos;
    // the texture of the tile
    sf::Texture texture;
    // the sprite of the tile
    sf::Sprite sprite;
    // constructor
    GameTile(std::string,float,float,bool,bool);
    // set up the sprite
    bool setUpSprite(std::string);
    // TEST COLLISION
     sf::Sprite getSprite() { return sprite; }
};

#endif