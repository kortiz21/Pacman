#include "Headers/gameTile.h"

// constructor for the game tile
GameTile::GameTile(std::string textureName, float x, float y, bool passable, bool exit)
{
    if (!setUpSprite(textureName))
    {
        return;
    }
    pos = sf::Vector2f(x,y);
    sprite.setPosition(pos);
    isPassable = passable;
    isExit = exit;
}
// set up the sprite for the tile
bool GameTile::setUpSprite(std::string textureName)
{
    if (!texture.loadFromFile(textureName))
    {
        return false;
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,TILE_SIZE,TILE_SIZE));
    return true;
}