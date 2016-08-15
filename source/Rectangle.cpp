#include "Rectangle.h"

Rectangle::Rectangle(float _leftTopX, float _leftTopY, float _horizontalSide, float _verticalSide):
	leftTopX(_leftTopX), leftTopY(_leftTopY), horizontalSide(_horizontalSide), verticalSide(_verticalSide){}

bool Rectangle::contain(float x, float y) { 
	if (leftTopX <= x && x <= leftTopX + horizontalSide &&
		leftTopY <= y && y <= leftTopY + verticalSide)
		return true;
	return false;
}

bool Rectangle::contain(Rectangle &otherRectangle) { 
	if (contain(otherRectangle.getLeftTopX(), otherRectangle.getLeftTopY()) ||
		contain(otherRectangle.getLeftTopX(), otherRectangle.getLeftTopY() + otherRectangle.getVerticalSide()) ||
		contain(otherRectangle.getLeftTopX() + otherRectangle.getHorizontalSide(), otherRectangle.getLeftTopY()) ||
		contain(otherRectangle.getLeftTopX()+otherRectangle.getHorizontalSide(), otherRectangle.getLeftTopY() + otherRectangle.getVerticalSide()))
		return true;
	return false;
}

bool Rectangle::collide(Rectangle &otherRectangle) { // czy containm sie w danym otherm prostokacie lub czy ktorys z punktow innego Rectanglea jest w tym prostokacie
	if (otherRectangle.contain(*this) || 
		contain(otherRectangle) )
		return true;
	return false;
}

float Rectangle::getLeftTopX() { return leftTopX; }
float Rectangle::getLeftTopY() { return leftTopY; }
float Rectangle::getHorizontalSide() { return horizontalSide; }
float Rectangle::getVerticalSide() { return verticalSide; }
