#include "Body.h"

Body::Body(CIw2DImage* _image, float _leftTopX, float _leftTopY): image(_image) {
	radius = _image->GetHeight()/2;
	centerX = _leftTopX + radius;
	centerY = _leftTopY + radius;
    
    
    verticalSide = sqrt(2)*radius;
    horizontalSide = sqrt(2)*radius;
    dPos = (2 * radius - verticalSide) / 2;
    leftTopX = _leftTopX + dPos;
    leftTopY = _leftTopY + dPos;
}

void Body::draw() {
	if (back)back->draw(); //rekurencyjnie rysuje reszte Snake'a
	Iw2DDrawImage(image, CIwFVec2(leftTopX-dPos, leftTopY-dPos));
}

std::pair<float, float> Body::lastMove() {
	if (movesMemory.empty())return noEnoughMemory;
	if (distance(movesMemory.front(), std::make_pair(centerX,centerY)) < radius) return noEnoughMemory; //dbam aby czesci ciala Snake'a byly odleglo o siebie o dl radiusia
	return movesMemory.front();									// bez tego ifa kolejne czesci moglby byc na sobie 
}

void Body::moveToPosition(float newX, float newY) {
	saveMove(newX, newY);
	setPosition(newX, newY);
}

void Body::saveMove(float newX, float newY) {
	movesMemory.push(std::make_pair(newX, newY));
	while (!movesMemory.empty() && distance(movesMemory.front(), std::make_pair(centerX, centerY)) > radius) // dbamy aby aktualna pozycja od ostatniego zapamietanego bylo niewieksza niz radius
		movesMemory.pop();																// zakldam ze nowa pozycja bedzie bedzie odlegla co najmniej o radius od ostatniego zapamietanego
}

void Body::setPosition(float newCenterX, float newCenterY) {
	centerX = newCenterX; centerY = newCenterY;
	leftTopX = centerX - radius + dPos; leftTopY = centerY - radius +dPos;
}
std::weak_ptr<Body> Body::getFront() {
    return front;
}

void Body::setImage(CIw2DImage* _image) {
    image = _image;
}

float Body::distance(std::pair<float, float> Pkt1, std::pair<float, float> Pkt2) {
	return sqrt((Pkt1.first - Pkt2.first)*(Pkt1.first - Pkt2.first) + (Pkt1.second - Pkt2.second)*(Pkt1.second - Pkt2.second));
}
