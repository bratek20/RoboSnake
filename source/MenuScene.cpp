#include "MenuScene.h"

MenuScene::MenuScene() {
	gameStartButton = Button(Assets::instance().startButton, 100, 100);
}

void MenuScene::update() {
	if (gameStartButton.isPressed())
		nextScene = new GameScene;
}

void MenuScene::draw() {
	gameStartButton.draw();
}