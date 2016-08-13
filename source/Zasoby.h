#ifndef Zasoby_h
#define Zasoby_h

#include "Iw2D.h"

class Zasoby
{
public:
	CIw2DImage* przyciskStart,*przyciskWyjscie;
	static Zasoby& instancja() { 
		static Zasoby *jedynaInstancja = new Zasoby(); //leniwa inicjalizacja
		return *jedynaInstancja;
	}
	~Zasoby();
private:
	Zasoby();
	
};

#endif 
