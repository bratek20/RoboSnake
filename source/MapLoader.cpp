#include "MapLoader.h"

void MapLoader::loadMap(MapLevel level, std::vector<Obstacle>& obstacles) {
    switch (level) {
    case Level1:
        loadFrame(obstacles);
        break;
    case Level2:
        loadFrame(obstacles);
        obstacles.push_back(Obstacle(Assets::instance().obstacle, 200, 200, 3, 3));//przykladowa kreacja map
        break;
    case Level3:
        break;
    default:
        break;
    }
}

void MapLoader::loadFrame(std::vector<Obstacle>& obstacles) {
    obstacles.push_back( Obstacle(Assets::instance().obstacle, 0, 0, 16, 1) );
    obstacles.push_back( Obstacle(Assets::instance().obstacle, 0, 0, 1, 24) );
    obstacles.push_back( Obstacle(Assets::instance().obstacle, 0, 460, 16, 1) );
    obstacles.push_back( Obstacle(Assets::instance().obstacle, 300, 0, 1, 24) );
}