#include "Cialo.h"

Cialo::Cialo(CIw2DImage* _grafika, float _lewyGornyX, float _lewyGornyY):
	Prostokat(_lewyGornyX, _lewyGornyY, _grafika->GetWidth(), _grafika->GetHeight()), grafika(_grafika) {
	promien = _grafika->GetHeight()/2;
	srodekX = _lewyGornyX + promien;
	srodekY = _lewyGornyY + promien;
}

void Cialo::rysuj() {
	if (tyl)tyl->rysuj(); //rekurencyjnie rysuje reszte Snake'a
	Iw2DDrawImage(grafika, CIwFVec2(lewyGornyX, lewyGornyY));
}

std::pair<float, float> Cialo::ostatniRuch() {
	if (pamiecRuchow.empty())return zaMaloPamieci;
	if (odleglosc(pamiecRuchow.front(), std::make_pair(srodekX,srodekY)) < promien) return zaMaloPamieci; //dbam aby czesci ciala Snake'a byly odleglo o siebie o dl promienia
	return pamiecRuchow.front();									// bez tego ifa kolejne czesci moglby byc na sobie 
}

void Cialo::idzNaPozycje(float nowyX, float nowyY) {
	zapamietajRuch(nowyX, nowyY);
	ustawPozycje(nowyX, nowyY);
}

void Cialo::zapamietajRuch(float nowyX, float nowyY) {
	pamiecRuchow.push(std::make_pair(nowyX, nowyY));
	while (odleglosc(pamiecRuchow.front(), std::make_pair(srodekX, srodekY)) > promien) // dbamy aby aktualna pozycja od ostatniego zapamietanego bylo niewieksza niz promien
		pamiecRuchow.pop();																// zakldam ze nowa pozycja bedzie bedzie odlegla co najmniej o promien od ostatniego zapamietanego
}

void Cialo::ustawPozycje(float nowySrodekX, float nowySrodekY) {
	srodekX = nowySrodekX; srodekY = nowySrodekY;
	lewyGornyX = srodekX - promien; lewyGornyY = srodekY - promien;
}

float Cialo::odleglosc(std::pair<float, float> Pkt1, std::pair<float, float> Pkt2) {
	return sqrt((Pkt1.first - Pkt2.first)*(Pkt1.first - Pkt2.first) + (Pkt1.second - Pkt2.second)*(Pkt1.second - Pkt2.second));
}
