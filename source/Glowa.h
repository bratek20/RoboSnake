#ifndef Glowa_h
#define Glowa_h

#include "Cialo.h"
#include "s3e.h"
#include "Ogon.h"
#include "Zasoby.h"

class Glowa : public Cialo {
private:
	bool zainicjalizowany; //zmienna okreslajaca czy przeprowadzilem inicjalizacje
	void inicjalizuj(); //uzywam shared_from_this wiec czesc inicjalizacji musi byc poza konstruktorem

	std::shared_ptr<Ogon>ostatniOgon;//wskaznik do ostatniej czesci ogonu, potrzebne do dodawania kolejnych czesci
	
	//zmienne i metody potrzbne do poruszania
	float katPoruszania; //odchylenie od poziomu pozwalajace sterowac, przesuwac itp
	const float predkoscPoruszania = 3.5f; //stala predkosc przemiszczania
	const float zmianaKataPoruszania = 6.66f; //zmienna okreslajaca o ile zmienia sie kat podczas jednej klatki
	void zmienKatPoruszania(float nacisnietyX, float nacisnietyY);//wykrywa po ktorej stronie glowy nacisniety, zmienia kat
	void poruszSie(); //oblicza nowa pozycje 

	//funkcje pomocnicze
	float iloczynWektorowy(std::pair<float, float> Pkt1, std::pair<float, float> Pkt2, std::pair<float, float> Pkt3);
public:
	Glowa() {};
	Glowa(float _lewyGornyX, float _lewyGornyY);
	void uaktualnij();
	void dolozOgon(); // doklada nowy ogon na koniec
};

#endif 


