#ifndef Ogon_h
#define Ogon_h

#include "Cialo.h"
#include "Zasoby.h"

class Ogon : public Cialo {
private:
public:
	Ogon(std::shared_ptr<Cialo> _przod, float _lewyGornyX, float _lewyGornyY);
	void uaktualnij();
	std::shared_ptr<Cialo> dolozOgon();//doklada nowy ogon, zwraca jego wskaznik, potrzebne dla Glowa aby widziec koniec swojego ogona
};

#endif
