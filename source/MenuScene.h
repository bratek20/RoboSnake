#ifndef MenuScene_h
#define MenuScene_h

#include "Scene.h"
#include "GameScene.h"
#include "Button.h"
#include "Assets.h"

class MenuScene: public Scene {
private:
	Button gameStartButton;
public:
	MenuScene();
	void update();
	void draw();

};

#endif 

