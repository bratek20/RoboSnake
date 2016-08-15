#include "Reward.h"

Reward::Reward(){
    image = Assets::instance().reward;
    horizontalSide = image->GetWidth();
    verticalSide = image->GetHeight();
    reset();
}

void Reward::reset() {
    visible = false;
    currentTime = 0;
    leftTopX = 20 + rand() % 260;
    leftTopY = 20 + rand() % 420;
    
    int tailType = rand() % 7;
    if (tailType == 0) rewardType = strongTail;
    else rewardType = weakTail;
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

TailType Reward::claimReward() {
    TailType currentReward = rewardType; 

    reset();

    return currentReward;
}

bool Reward::isVisible() {
    return visible;
}