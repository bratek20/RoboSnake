#include "Obstacle.h"

Obstacle::Obstacle(CIw2DImage* _image, float _leftTopX, float _leftTopY, int _verticalAmount, int _horizontalAmount):
	Rectangle(_leftTopX, _leftTopY, _image->GetWidth()*_verticalAmount, _image->GetHeight()*_horizontalAmount),
	image(_image),verticalAmount(_verticalAmount),horizontalAmount(_horizontalAmount){}

void Obstacle::draw() {
	for (int vertical = 0;  vertical < verticalAmount; vertical++)
		for (int horizontal = 0; horizontal < horizontalAmount; horizontal++)
			Iw2DDrawImage(image, CIwFVec2( leftTopX + vertical*image->GetWidth(), 
											 leftTopY + horizontal*image->GetHeight() ));
}