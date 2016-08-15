#ifndef MapLoader_h
#define MapLoader_h

#include "vector"
#include "Obstacle.h"
#include "Assets.h"

enum MapLevel {
    Level1, Level2, Level3
};

//klasa statyczna do ladowania map
class MapLoader {
public:
    static void loadMap(MapLevel level, std::vector<Obstacle>& obstacles);
private:
    MapLoader() {}
    static void loadFrame(std::vector<Obstacle>& obstacles); //budowanie podstawowej obramowki 
};



#endif 

