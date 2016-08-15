#ifndef Assets_h
#define Assets_h

#include "Iw2D.h"

class Assets
{
public:
	CIw2DImage* startButton,*exitButton, *head, *weakTail, *strongTail, *obstacle, *reward;
	CIw2DFont* font;
	static Assets& instance() { 
		static Assets *theInstance = new Assets(); //leniwa inicjalizacja
		return *theInstance;
	}
	~Assets();
private:
	Assets();
	
};

#endif 
