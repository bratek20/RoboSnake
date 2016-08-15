#ifndef Button_h
#define Button_h

#include "Iw2D.h"
#include "Rectangle.h"
#include "s3ePointer.h"

class Button : public Rectangle{
private:
	CIw2DImage* image;
public:
	Button() {}
	Button(CIw2DImage* _icon, float _leftTopX,float _leftTopY); //wybieramy grafike dla przycisku oraz polozenie an ekranie
	bool isPressed(); // czy przycisk jest nacisniety, wymaga s3ePointerUpdate();
	void draw(); //rysuje przycisk
};

#endif 

