#ifndef Cialo_h
#define Cialo_h

#include "Prostokat.h"
#include "Iw2D.h"
#include "algorithm"
#include "queue"
#include "memory"
#include "cmath"

// cialo dla snake'a, bedzie dziedziczone przez glowe oraz tulow
// pozwalam na shared_from_this bo bede potrzebowac tego aby tworzyc weak_ptr

class Cialo : public Prostokat, public std::enable_shared_from_this<Cialo> { 
private:																	
	CIw2DImage* grafika;

	std::queue< std::pair<float, float> >pamiecRuchow; // zachowuje ostatnie kilka ruchow, potrzebne do przemieszczania sie fragmentow snake'a  
	//funkcje pomocnicze
	void zapamietajRuch(float nowyX, float nowyY);//doklada nowa pozycje do pamieciRuchow
	void ustawPozycje(float nowySrodekX, float nowySrodekY);//ustawia nowa pozycje, poprawiajac rowniez ulozenie prostokata
	float odleglosc(std::pair<float, float> Pkt1, std::pair<float, float> Pkt2);//oblicza odleglosc euklidesowa
protected:
	//wskazniki ustawiane sa w klasach ktore beda dziedziczyc
	std::weak_ptr<Cialo>przod;//wskaznik na czesc ciala przede mna, ktory mnie utworzyl i za nim podazam
	std::shared_ptr<Cialo>tyl;//wskaznik na czesc ciala ktory utworzylem i ktory za mna podaza

	float promien; // snake bedzie skladac sie z okregow
	float srodekX, srodekY; //srodek ciala (okregu)
	const std::pair<float, float> zaMaloPamieci = std::make_pair(-1, -1); // zwracane gdy kolejka nie pamieta conajmniej maxPamiecRuchow
	void idzNaPozycje(float nowyX, float nowyY);//przemiszcza cialo na pozycje (nowyX, nowyY), zapamietujac ruch

public:
	Cialo(){}
	Cialo(CIw2DImage* _grafika, float _lewyGornyX, float _lewyGornyY);//grafika powinna przedstawiac okrag
	virtual void uaktualnij() = 0;
	void rysuj();
	std::pair<float, float> ostatniRuch(); //zwraca ostatni zapamietany ruch, potrzebne aby ogon ladnie za soba podazal
};
#endif 
