#include "ScenaMenu.h"

ScenaMenu::ScenaMenu() {
	przyciskStartGry = Przycisk(Zasoby::instancja().przyciskStart, 100, 100);
}
void ScenaMenu::uaktualnij() {
	if (przyciskStartGry.jestNacisniety())
		nastepnaScena = new ScenaGry;
}

void ScenaMenu::rysuj() {
	przyciskStartGry.rysuj();
}