#ifndef ScenaMenu_h
#define ScenaMenu_h

#include "Scena.h"
#include "ScenaGry.h"
#include "Przycisk.h"
#include "Zasoby.h"

class ScenaMenu :public Scena {
private:
	Przycisk przyciskStartGry;
public:
	ScenaMenu();
	~ScenaMenu();
	void uaktualnij();
	void rysuj();

};

#endif 

