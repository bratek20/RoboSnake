#include "Cialo.h"

Cialo::Cialo(CIw2DImage* _grafika, float _lewyGornyX, float _lewyGornyY):
	Prostokat(_lewyGornyX, _lewyGornyY, _grafika->GetWidth(), _grafika->GetHeight()), grafika(_grafika) {
	promien = _grafika->GetHeight()/2;
	srodekX = _lewyGornyX + promien;
	srodekY = _lewyGornyY + promien;
}

void Cialo::rysuj() {
	Iw2DDrawImage(grafika, CIwFVec2(lewyGornyX, lewyGornyY));
}