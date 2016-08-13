#include "ScenaGry.h"

ScenaGry::ScenaGry() {
	przyciskWyjscieZGry = Przycisk(Zasoby::instancja().przyciskWyjscie, 300, 0);
	glowa = new Glowa(Zasoby::instancja().glowa, 100, 100);
}

ScenaGry::~ScenaGry() {
	delete glowa;
	puts("usuwam scenaGry");
}
void ScenaGry::uaktualnij() {
	if (przyciskWyjscieZGry.jestNacisniety())
		nastepnaScena = new ScenaMenu;
	glowa->uaktualnij();
}

void ScenaGry::rysuj() {
	glowa->rysuj();
	przyciskWyjscieZGry.rysuj();
}