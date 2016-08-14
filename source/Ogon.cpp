#include "Ogon.h"

Ogon::Ogon(std::shared_ptr<Cialo> _przod, float _lewyGornyX, float _lewyGornyY) :
	Cialo(Zasoby::instancja().glowa, _lewyGornyX, _lewyGornyY){
	przod = _przod;
}

void Ogon::uaktualnij() {
	if (przod.expired())return;//dodane dla bezpieczenstwa
	auto nowyRuch = przod.lock()->ostatniRuch();
	if (nowyRuch != zaMaloPamieci)  //moge juz podazac za swoim przodem
		idzNaPozycje(nowyRuch.first, nowyRuch.second);

	if (tyl)tyl->uaktualnij();
}

std::shared_ptr<Cialo> Ogon::dolozOgon() {
	tyl = std::shared_ptr<Cialo>(new Ogon(shared_from_this(), lewyGornyX, lewyGornyY));
	return tyl;
}