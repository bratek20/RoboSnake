#ifndef Glowa_h
#define Glowa_h

#include "Cialo.h"
#include "s3e.h"
#include "algorithm"
#include "cmath"

class Glowa : public Cialo {
private:
	float katPoruszania; //odchylenie od poziomu pozwalajace sterowac, przesuwac itp
	const float predkoscPoruszania = 3; //stala predkosc przemiszczania
	const float zmianaKataPoruszania = 3; //o ile zmienia sie kat podczas jednej klatki
	void zmienKatPoruszania(float nacisnietyX, float nacisnietyY);//wykrywa po ktorej stronie glowy nacisniety, zmienia kat
	void poruszSie();

	//funkcje pomocnicze
	float iloczynWektorowy(std::pair<float, float> Pkt1, std::pair<float, float> Pkt2, std::pair<float, float> Pkt3);
public:
	Glowa() {};
	Glowa(CIw2DImage* _grafika, float _lewyGornyX, float _lewyGornyY);
	void uaktualnij();
};

#endif 


