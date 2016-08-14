#include "Glowa.h"

Glowa::Glowa(float _lewyGornyX, float _lewyGornyY):
	Cialo(Zasoby::instancja().glowa, _lewyGornyX, _lewyGornyY),katPoruszania(0),zainicjalizowany(false){
}

void Glowa::uaktualnij() {
	if (!zainicjalizowany)inicjalizuj();

	if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) == S3E_POINTER_STATE_DOWN) //dokadajac klase input moze byc AI
		zmienKatPoruszania(s3ePointerGetX(), s3ePointerGetY());
	
	poruszSie();

	if (tyl)tyl->uaktualnij();
}

void Glowa::inicjalizuj() {
	zainicjalizowany = true;
	tyl = std::shared_ptr<Cialo>(new Ogon(shared_from_this(), lewyGornyX, lewyGornyY));//tutam ustawiam tyl dla Glowy
	ostatniOgon = std::static_pointer_cast<Ogon>(tyl);

	int ile = 10; // kod do usuniecia
	while(ile--) // tylko zeby pokazac jak 
		dolozOgon(); // fajnie dziala mozliwosc wydluzania Snake'a

}

void Glowa::dolozOgon() {
	ostatniOgon = std::static_pointer_cast<Ogon>(ostatniOgon->dolozOgon());
}
void Glowa::zmienKatPoruszania(float nacisnietyX, float nacisnietyY) {
	//pierwszy pkt to po prostu srodek ciala
	//drugi pkt to wyimaginowany pkt w ktorym znalazlby sie Snake poruszajac sie z aktualnym katem
	//trzeci pkt to miejsce nacisniecia 
	//jesli znak iloczyn > 0 to skrecamy w lewo tz. zwiekszamy kat poruszania, skrecajac w prawo zmniejszamy kat

	float znakIloczynu =
		iloczynWektorowy(std::make_pair(srodekX, srodekY),
			std::make_pair(srodekX + 10*(float)cos(katPoruszania * PI/180), srodekY + 10*(float)sin(katPoruszania * PI/180)),
				std::make_pair(nacisnietyX, nacisnietyY) );

	if (znakIloczynu > 0)katPoruszania += zmianaKataPoruszania;
	else if (znakIloczynu < 0)katPoruszania -= zmianaKataPoruszania;
}

void Glowa::poruszSie() {
	if (katPoruszania < 0)katPoruszania += 360;
	if (katPoruszania >= 360)katPoruszania -= 360;

	idzNaPozycje(srodekX + cos(katPoruszania *  PI / 180) * predkoscPoruszania,		//rozkladam vector na skladowa pozioma
		srodekY + sin(katPoruszania * PI / 180) * predkoscPoruszania); //i pionowa
}

float Glowa::iloczynWektorowy(std::pair<float, float> Pkt1, std::pair<float, float> Pkt2, std::pair<float, float> Pkt3) {
	Pkt3.first -= Pkt1.first; Pkt3.second -= Pkt1.second;
	Pkt2.first -= Pkt1.first; Pkt2.second -= Pkt1.second;

	return Pkt2.first*Pkt3.second - Pkt2.second*Pkt3.first;
}


