#ifndef ScenaGry_h
#define ScenaGry_h

#include "Zasoby.h"
#include "Scena.h"
#include "ScenaMenu.h"
#include "Przycisk.h"
#include "Glowa.h"
class ScenaGry : public Scena {
private:
	Przycisk przyciskWyjscieZGry;
	Glowa* glowa;
public:
	ScenaGry();
	~ScenaGry();
	void uaktualnij();
	void rysuj();
};

#endif 

