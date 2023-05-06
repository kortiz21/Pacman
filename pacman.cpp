#include "pacman.h"
#include "constants.h"


Pacman::Pacman() :
        direction(0),
        pos(0,0)
{
}

void Pacman::draw(sf::RenderWindow &window){

    sprite.setPosition(pos);
    texture.loadFromFile("Images/player.png");
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,TILE_SIZE,TILE_SIZE));
    window.draw(sprite);
}
void Pacman::set_position(float x, float y) {
    pos = sf::Vector2f(x,y);
}
void Pacman::update(std::vector<std::string> &map) {
    // direction is 0 for right, 1 for up, 2 for left, 3 for down
    if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        //if (map[pos.y/TILE_SIZE+PACMAN_SPEED][pos.x/TILE_SIZE] != 'x') {
            direction = 3;
        //}
    }
    else if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        //if (map[pos.y/TILE_SIZE][pos.x/TILE_SIZE-PACMAN_SPEED] != 'x') {
            direction = 2;
        //}
    }
    else if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        //if(map[pos.y/TILE_SIZE][pos.x/TILE_SIZE+PACMAN_SPEED] != 'x') {
            direction = 0;
        //}
    }
    else if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
       //if (map[pos.y/TILE_SIZE-PACMAN_SPEED][pos.x/TILE_SIZE] != 'x') {
            direction = 1;
        //}
    }

    // move pacman in the direction he is facing by PACMAN_SPEED
    if (direction == 0)
    {
        pos.x += PACMAN_SPEED;
    }
    else if (direction == 1)
    {
        pos.y -= PACMAN_SPEED;
    }
    else if (direction == 2)
    {
        pos.x -= PACMAN_SPEED;
    }
    else if (direction == 3)
    {
        pos.y += PACMAN_SPEED;
    }
}