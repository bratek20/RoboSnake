#include "GameScene.h"

GameScene::GameScene() {
	exitGameButton = Button(Assets::instance().exitButton, 300, 0);
	
    snake = std::shared_ptr<Head>(new Head(100, 100));
    
    MapLoader::loadMap(Level1, obstacles);
}

void GameScene::update() {
	if (exitGameButton.isPressed())
		nextScene = new MenuScene;

    detectCollision();

	snake->update();
    reward.update();
}

void GameScene::draw() {
    reward.draw();
    snake->draw();

	for (int i=0; i<obstacles.size();i++)
		obstacles[i].draw();
	
	exitGameButton.draw();
}

void GameScene::detectCollision() {
    for (int i = 0; i < obstacles.size(); i++) //kolizje ze scianami
        if (obstacles[i].collide(*snake))
            nextScene = new EndGameScene;

    if (reward.isVisible() && reward.collide(*snake))
        snake->addTail(reward.claimReward());
}