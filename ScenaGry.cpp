#include "ScenaGry.h"

ScenaGry::ScenaGry() {
	przyciskWyjscieZGry = Przycisk(Zasoby::instancja().przyciskWyjscie, 300, 0);
}

void ScenaGry::uaktualnij() {
	if (przyciskWyjscieZGry.jestNacisniety())
		nastepnaScena = new ScenaMenu;
}

void ScenaGry::rysuj() {
	przyciskWyjscieZGry.rysuj();
}