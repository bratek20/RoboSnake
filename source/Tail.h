#ifndef Tail_h
#define Tail_h

#include "Body.h"
#include "Assets.h"

enum TailType {
    initialTail, //poczatkowy - nie ulega kolizji, tworzony pdoczas tworzenia snake'a
    weakTail, //podczas kolizji ulega zniszczeniu wraz z wszystkim co ma za soba
    strongTail //niezniszczalny, zabija snake'a gdy w niego wjedzie

};
class Tail : public Body {
private:
    TailType tailType;
public:
	Tail(TailType _tailType, std::shared_ptr<Body> _front, float _leftTopX, float _leftTopY);
	void update();
	std::shared_ptr<Body> addTail(TailType _tailType);//doklada nowy Tail, zwraca jego wskaznik, potrzebne dla Glowa aby widziec koniec swojego Taila
};

#endif
