#ifndef ScenaGry_h
#define ScenaGry_h

#include "Zasoby.h"
#include "Scena.h"
#include "ScenaMenu.h"
#include "Przycisk.h"

class ScenaGry : public Scena {
private:
	Przycisk przyciskWyjscieZGry;
public:
	ScenaGry();
	void uaktualnij();
	void rysuj();
};

#endif 

