#include "Headers/pacman.h"
#include "Headers/constants.h"
#include <iostream>
#include <cmath>

Pacman::Pacman() : direction(0),
                   pos(0, 0)
{
}

void Pacman::draw(sf::RenderWindow &window)
{

    sprite.setPosition(pos);
    texture.loadFromFile("Images/player.png");
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, TILE_SIZE, TILE_SIZE));
    window.draw(sprite);
}
void Pacman::set_position(float x, float y)
{
    pos = sf::Vector2f(x, y);
}

void Pacman::update(std::vector<std::string> &map) {
    // direction is 0 for right, 1 for up, 2 for left, 3 for down
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (map[((pos.y)/TILE_SIZE+PACMAN_SPEED)][(pos.x/TILE_SIZE)] != 'x') {
            direction = 3;
            std::cout << "down" << std::endl;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if (map[(pos.y/TILE_SIZE)][((pos.x-PACMAN_SPEED)/TILE_SIZE)] != 'x') {
            direction = 2;
            std::cout << "left" << std::endl;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if(map[(pos.y/TILE_SIZE)][((pos.x)/TILE_SIZE+PACMAN_SPEED)] != 'x') {
            direction = 0;
            std::cout << "right" << std::endl;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
       if (map[((pos.y-PACMAN_SPEED)/TILE_SIZE)][(pos.x/TILE_SIZE)] != 'x') {
            direction = 1;
            std::cout << "up" << std::endl;
        }
    }

    // move pacman in the direction he is facing by PACMAN_SPEED
    if (direction == 0 && map[(pos.y/TILE_SIZE)][((pos.x)/TILE_SIZE+PACMAN_SPEED)] != 'x')
    {
        pos.x += PACMAN_SPEED;
    }
    else if (direction == 1 && map[((pos.y-PACMAN_SPEED)/TILE_SIZE)][(pos.x/TILE_SIZE)] != 'x')
    {
        pos.y -= PACMAN_SPEED;
    }
    else if (direction == 2 && map[(pos.y/TILE_SIZE)][((pos.x-PACMAN_SPEED)/TILE_SIZE)] != 'x')
    {
        pos.x -= PACMAN_SPEED;
    }
    else if (direction == 3 && map[((pos.y)/TILE_SIZE+PACMAN_SPEED)][(pos.x/TILE_SIZE)] != 'x')
    {
        pos.y += PACMAN_SPEED;
    }
}

    // void Pacman::update(std::vector<std::string> &map) {
    //     // direction is 0 for right, 1 for up, 2 for left, 3 for down
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    //     {
    //         if (map[pos.y/TILE_SIZE+PACMAN_SPEED][pos.x/TILE_SIZE] != 'x') {
    //             direction = 3;
    //             std::cout << "down" << std::endl;
    //         }
    //     }
    //     else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    //     {
    //         if (map[pos.y/TILE_SIZE][pos.x/TILE_SIZE-PACMAN_SPEED] != 'x') {
    //             direction = 2;
    //             std::cout << "left" << std::endl;
    //         }
    //     }
    //     else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    //     {
    //         if(map[pos.y/TILE_SIZE][pos.x/TILE_SIZE+PACMAN_SPEED] != 'x') {
    //             direction = 0;
    //             std::cout << "right" << std::endl;
    //         }
    //     }
    //     else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    //     {
    //        if (map[pos.y/TILE_SIZE-PACMAN_SPEED][pos.x/TILE_SIZE] != 'x') {
    //             direction = 1;
    //             std::cout << "up" << std::endl;
    //         }
    //     }

    //     // move pacman in the direction he is facing by PACMAN_SPEED
    //     if (direction == 0 && map[pos.y/TILE_SIZE][pos.x/TILE_SIZE+PACMAN_SPEED] != 'x')
    //     {
    //         pos.x += PACMAN_SPEED;
    //     }
    //     else if (direction == 1 && map[pos.y/TILE_SIZE-PACMAN_SPEED][pos.x/TILE_SIZE] != 'x')
    //     {
    //         pos.y -= PACMAN_SPEED;
    //     }
    //     else if (direction == 2 && map[pos.y/TILE_SIZE][pos.x/TILE_SIZE-PACMAN_SPEED] != 'x')
    //     {
    //         pos.x -= PACMAN_SPEED;
    //     }
    //     else if (direction == 3 && map[pos.y/TILE_SIZE+PACMAN_SPEED][pos.x/TILE_SIZE] != 'x')
    //     {
    //         pos.y += PACMAN_SPEED;
    //     }
    // }