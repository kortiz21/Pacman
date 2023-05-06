#include <SFML/Graphics.hpp>
#include <vector>

#include "constants.h"
#include "gameTile.cpp"
#include "gameWorld.cpp"
#include "pacman.cpp"

int main()
{
     // maze 1
    std::vector<std::string> map = {
        "xxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
        "xxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
        "xxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
        "x+....+.....+xxx+.....+....+x",
        "x.xxxx.xxxxx.xxx.xxxxx.xxxx.x",
        "x.xxxx.xxxxx.xxx.xxxxx.xxxx.x",
        "x.xxxx.xxxxx.xxx.xxxxx.xxxx.x",
        "x+....+..+..+...+..+..+....+x",
        "x.xxxx.xx.xxxxxxxxx.xx.xxxx.x",
        "x.xxxx.xx.xxxxxxxxx.xx.xxxx.x",
        "x+....+xx+..+xxx+..+xx+....+x",
        "xxxxxx.xxxxx.xxx.xxxxx.xxxxxx",
        "xxxxxx.xxxxx.xxx.xxxxx.xxxxxx",
        "xxxxxx.xx+..+.e.+..+xx.xxxxxx",
        "xxxxxx.xx.xxx===xxx.xx.xxxxxx",
        "xxxxxx.xx.xxxeeexxx.xx.xxxxxx",
        "+.....+..+xxxxxxxxx+..+.....+",
        "xxxxxx.xx.xxxxxxxxx.xx.xxxxxx",
        "xxxxxx.xx.xxxxxxxxx.xx.xxxxxx",
        "xxxxxx.xx+.........+xx.xxxxxx",
        "xxxxxx.xx.xxxxxxxxx.xx.xxxxxx",
        "xxxxxx.xx.xxxxxxxxx.xx.xxxxxx",
        "x+....+..+..+xxx+..+..+....+x",
        "x.xxxx.xxxxx.xxx.xxxxx.xxxx.x",
        "x.xxxx.xxxxx.xxx.xxxxx.xxxx.x",
        "x+.+xx+..+..+.p.+..+..+xx+.+x",
        "xxx.xx.xx.xxxxxxxxx.xx.xx.xxx",
        "xxx.xx.xx.xxxxxxxxx.xx.xx.xxx",
        "x+.+..+xx+..+xxx+..+xx+..+.+x",
        "x.xxxxxxxxxx.xxx.xxxxxxxxxx.x",
        "x.xxxxxxxxxx.xxx.xxxxxxxxxx.x",
        "x+..........+...+..........+x",
        "xxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
        "xxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
        "xxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
    };

    // Create the main window 928x1120
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pacman");

    Pacman pacman = Pacman();
    GameWorld gameWorld = GameWorld(map, pacman);

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
        // Update pacman
        pacman.update(map);
        // Clear screen
        window.clear();
        // Draw stuff
        for (int i = 0; i < GRID_LENGTH; i++)
        {
            for (int j = 0; j < GRID_WIDTH; j++)
            {
                window.draw(gameWorld.tiles[i][j]->sprite);
            }
        }
        // Draw pacman
        pacman.draw(window);
        // Update the window
        window.display();
    }

    return 0;
}