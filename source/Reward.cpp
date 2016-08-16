#include "Reward.h"

Reward::Reward(std::vector<Obstacle>& _obstacles){
    obstacles = _obstacles;
    image = Assets::instance().reward;
    horizontalSide = image->GetWidth();
    verticalSide = image->GetHeight();
    reset();
}

void Reward::reset() {
    visible = false;
    currentTime = 0;
    
    randomPosition();
    
    int tailType = rand() % strongTailPropability;
    if (tailType == 0) rewardType = strongTail;
    else rewardType = weakTail;
}
void Reward::randomPosition() {
    bool obstaclesCollision = true;
    while (obstaclesCollision) { //losujemy nowa pozycje dopoki nagroda koliduje z przeszkodami
        leftTopX = rand() % 320;
        leftTopY = rand() % 480;
        
        obstaclesCollision = false;
        for (int i = 0; i < obstacles.size(); i++)
            if (collide(obstacles[i]))
                obstaclesCollision = true;
    }
}
void Reward::update() {
    currentTime++;
    if (currentTime > spawnTime)
        visible = true;
}

void Reward::draw() {
    if (visible) 
        Iw2DDrawImage(image, CIwFVec2(leftTopX, leftTopY));
    
}

void Reward::claimReward(std::shared_ptr<Head> snake) {
    for(int i=0;i<rewardAmount;i++)
        snake->addTail(rewardType);

    reset();
}

bool Reward::isVisible() {
    return visible;
}