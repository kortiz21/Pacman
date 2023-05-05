#include <SFML/Graphics.hpp>
#include "gameTile.cpp"
#include "gameWorld.cpp"

int main()
{
    // Create the main window
    float windowHeight = 400;
    float windowWidth = 400;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Pacman");

    GameWorld gameWorld = GameWorld();

    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        // Event loop
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        // Draw stuff
        for (int i = 0; i < gameWorld.gridLength; i++)
        {
            for (int j = 0; j < gameWorld.gridLength; j++)
            {
                window.draw(gameWorld.tiles[i][j]->sprite);
            }
        }
        // Update the window
        window.display();
    }

    return 0;
}