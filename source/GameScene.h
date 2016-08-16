#ifndef GameScene_h
#define GameScene_h

#include "Assets.h"
#include "Scene.h"
#include "MenuScene.h"
#include "EndGameScene.h"
#include "Button.h"
#include "Head.h"
#include "Obstacle.h"
#include "MapLoader.h"
#include "Reward.h"

class GameScene : public Scene {
private:
	Button exitGameButton;
	std::shared_ptr<Head> snake;//glowa Snake'a 
    std::vector< Obstacle >obstacles;
    std::unique_ptr<Reward> reward;

    void detectCollision(); //funkcja obslugujaca kolizje: snake'a ze scianami, snake'a z samym soba oraz snake'a z nagrodami
public:
	GameScene();
	void update();
	void draw();
};

#endif 

