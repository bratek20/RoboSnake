#include "Tail.h"

Tail::Tail(TailType _tailType, std::shared_ptr<Body> _front, float _leftTopX, float _leftTopY) : tailType(_tailType),
    Body(Assets::instance().head, _leftTopX, _leftTopY){
    if (tailType == weakTail) setImage(Assets::instance().weakTail);
    if (tailType == strongTail) setImage(Assets::instance().strongTail);
    front = _front;
}

void Tail::update() {
	if (front.expired())return;//dodane dla bezpieczenstwa
	auto newMove = front.lock()->lastMove();
	if (newMove != noEnoughMemory)  //moge juz podazac za swoim frontem
		moveToPosition(newMove.first, newMove.second);

	if (back)back->update();
}

std::shared_ptr<Body> Tail::addTail(TailType _tailType) {
	back = std::shared_ptr<Body>(new Tail(_tailType, shared_from_this(), leftTopX - dPos, leftTopY - dPos));
	return back;
}
void Tail::cutTail() {
    back.reset();
}
TailType Tail::getTailType() {
    return tailType;
}