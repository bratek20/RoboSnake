#ifndef Obstacle_h
#define Obstacle_h

#include "Rectangle.h"
#include "Iw2D.h"

class Obstacle : public Rectangle {
private:
	CIw2DImage* image; 
	int horizontalAmount, verticalAmount;//ile powielenia danej grafiki w pionie/poziomie, oszczedza ilosc sprawdzen kolizji
public:
	Obstacle() {}
	Obstacle(CIw2DImage* _image, float _leftTopX, float _leftTopY, int _horizontalAmount, int _verticalAmount);
	void draw(); //rysuje horizontalAmount * verticalAmount blokow grafiki
};
#endif
