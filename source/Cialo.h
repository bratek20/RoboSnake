#ifndef Cialo_h
#define Cialo_h

#include "Prostokat.h"
#include "Iw2D.h"

class Cialo : public Prostokat { // cialo dla snake'a, bedize dziedziczone przez glowe oraz tulow
private:
	CIw2DImage* grafika;
protected:
	float promien; // snake bedzie skladac sie z okregow
	float srodekX, srodekY; //srodek ciala (okregu)
public:
	Cialo(){}
	Cialo(CIw2DImage* _grafika, float _lewyGornyX, float _lewyGornyY);//grafika powinna przedstawiac okrag
	virtual void uaktualnij() = 0;
	void rysuj();
};
#endif 
