#ifndef Rectangle_h
#define Rectangle_h

class Rectangle {
protected:
	float leftTopX, leftTopY, horizontalSide, verticalSide;

public:
	Rectangle() {}
	~Rectangle() {}
	Rectangle(float _leftTopX, float _leftTopY, float _horizontalSide, float _verticalSide);
	
	bool contain(float x, float y); // czy pkt (x,y) zawiera sie w prostokacie
	bool contain(Rectangle &otherRectangle);// czy prostokat zawiera jakis z 4 punktow danego inny prostokat
	bool collide(Rectangle &otherRectangle); // czy prostokat jakos koliduje z innym prostokatem

	float getLeftTopX();
	float getLeftTopY();
	float getHorizontalSide();
	float getVerticalSide();
};

#endif 

