#ifndef Przycisk_h
#define Przycisk_h

#include "Iw2D.h"
#include "Prostokat.h"
#include "s3ePointer.h"

class Przycisk : public Prostokat{
private:
	CIw2DImage* ikona;
public:
	Przycisk() {}
	Przycisk(CIw2DImage* _ikona,int _lewyGornyX,int _lewyGornyY); //wybieramy grafike dla przycisku oraz polozenie an ekranie
	bool jestNacisniety(); // czy przycisk jest nacisniety, wymaga s3ePointerUpdate();
	void rysuj(); //rysuje przycisk
};

#endif 

