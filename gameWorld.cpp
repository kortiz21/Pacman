#include "Headers/gameWorld.h"

// constructor for the game world
GameWorld::GameWorld(std::vector<std::string> &map, Pacman &pacman)
{

    // setup initial state
    setUpInitialState(map, pacman);
}

void GameWorld::setUpInitialState(std::vector<std::string> &map, Pacman &pacman)
{
    // setup exit position
    //exitPos = sf::Vector2i(1,0);
    // setup player position
    //playerPos = sf::Vector2i(gridLength-1,gridLength-1);

    // setup enemy positions
    setUpEnemyPositions();
    setUpTiles(map, pacman);

}

void GameWorld::setUpEnemyPositions()
{
    // clear the vector of enemy positions
    ghostPos.clear();
    //ghostPos.push_back(sf::Vector2i(0,2));
    //ghostPos.push_back(sf::Vector2i(6,0));
    //ghostPos.push_back(sf::Vector2i(2,7));
}

void GameWorld::setUpTiles(std::vector<std::string> &map, Pacman& pacman)
{
    // clear the vector of tiles
    tiles.clear();
   
    // create the tiles
    for (int i = 0; i < GRID_LENGTH; i++)
    {
        std::vector<GameTile *> row;
        for (int j = 0; j < GRID_WIDTH; j++)
        {            
            if (map[i][j] == 'x') {
                row.push_back(new GameTile("Images/wall.png",j*TILE_SIZE,i*TILE_SIZE,false,false));
            }
            else if (map[i][j] == '.') {
                row.push_back(new GameTile("Images/ground.png",j*TILE_SIZE,i*TILE_SIZE,true,false));
            }
            else if (map[i][j] == '+') {
                row.push_back(new GameTile("Images/ground.png",j*TILE_SIZE,i*TILE_SIZE,true,false));
            }
            else if (map[i][j] == '=') {
                row.push_back(new GameTile("Images/door.png",j*TILE_SIZE,i*TILE_SIZE,true,false));
            }
            else if (map[i][j] == 'e') {
                row.push_back(new GameTile("Images/enemy.png",j*TILE_SIZE,i*TILE_SIZE,true,false));
            }
            else if (map[i][j] == 'p') {
                row.push_back(new GameTile("Images/ground.png",j*TILE_SIZE,i*TILE_SIZE,true,false));
                pacman.set_position(j*TILE_SIZE, i*TILE_SIZE);
            }
        }
        tiles.push_back(row);
    }
}