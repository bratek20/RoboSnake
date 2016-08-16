#include "EndGameScene.h"

EndGameScene::EndGameScene() :
    retryButton(Button(Assets::instance().retryButton,100,100)),
    exitButton(Button(Assets::instance().exitButton, 300, 0)) {}

void EndGameScene::update() {
    if (retryButton.isPressed())
        nextScene = new GameScene;
	if (exitButton.isPressed())
		nextScene = new MenuScene;
}

void EndGameScene::draw() {
    retryButton.draw();
	exitButton.draw();

	Iw2DSetFont(Assets::instance().font);
	Iw2DDrawString("You Lost!", CIwFVec2(100, 20), CIwFVec2(100,100),
		IW_2D_FONT_ALIGN_CENTRE, IW_2D_FONT_ALIGN_CENTRE);
}