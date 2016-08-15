#ifndef EndGameScene_h
#define EndGameScene_h

#include "Scene.h"
#include "MenuScene.h"
#include "Button.h"
#include "Assets.h"
#include "Iw2D.h"

class EndGameScene : public Scene {
private:
	Button exitButton;
public:
	EndGameScene();
	void update();
	void draw();
};
#endif
