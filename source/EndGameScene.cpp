#include "EndGameScene.h"

EndGameScene::EndGameScene() :exitButton(Button(Assets::instance().exitButton, 300, 0)) {}

void EndGameScene::update() {
	if (exitButton.isPressed())
		nextScene = new MenuScene;
}

void EndGameScene::draw() {
	exitButton.draw();

	Iw2DSetFont(Assets::instance().font);
	Iw2DDrawString("You Lost!", CIwFVec2(100, 100), CIwFVec2(100,100),
		IW_2D_FONT_ALIGN_CENTRE, IW_2D_FONT_ALIGN_CENTRE);
}