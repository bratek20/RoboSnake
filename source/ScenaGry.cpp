#include "ScenaGry.h"

ScenaGry::ScenaGry() {
	przyciskWyjscieZGry = Przycisk(Zasoby::instancja().przyciskWyjscie, 300, 0);
	snake = std::shared_ptr<Glowa>(new Glowa(100, 100));
}

ScenaGry::~ScenaGry() {
	puts("usuwam scenaGry");
}
void ScenaGry::uaktualnij() {
	if (przyciskWyjscieZGry.jestNacisniety())
		nastepnaScena = new ScenaMenu;
	snake->uaktualnij();
}

void ScenaGry::rysuj() {
	snake->rysuj();
	przyciskWyjscieZGry.rysuj();
}