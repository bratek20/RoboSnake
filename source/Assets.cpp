#include "Assets.h"

Assets::Assets(){
	startButton = Iw2DCreateImage("textures/startButton.png");
	exitButton = Iw2DCreateImage("textures/exitButton.png");
	head = Iw2DCreateImage("textures/head.png");
    weakTail = Iw2DCreateImage("textures/weakTail.png");
    strongTail = Iw2DCreateImage("textures/strongTail.png");
    obstacle = Iw2DCreateImage("textures/obstacle.png");
    reward = Iw2DCreateImage("textures/reward.png");

	font = Iw2DCreateFont("fonts/arial14.gxfont");
}
Assets::~Assets() {
	delete startButton;
	delete exitButton;
	delete head;
    delete weakTail;
    delete strongTail;
    delete obstacle;
    delete reward;

	delete font;
}