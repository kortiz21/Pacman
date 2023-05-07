#include <SFML/Graphics.hpp>
#include <string>

#ifndef PACMAN_H
#define PACMAN_H

class Pacman
{
    int direction;
    // the position of pacman, contains x and y coordinates
    sf::Vector2f pos;
    sf::Sprite sprite;
    sf::Texture texture;

public:
    Pacman();
    void draw(sf::RenderWindow &window);
    void set_position(float x, float y);
    void update(std::vector<std::string> &map);
    // TEST COLLISION
    sf::Vector2f getPosition() { return pos; }
    sf::Sprite getSprite() { return sprite; }
};

#endif