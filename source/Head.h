#ifndef Head_h
#define Head_h

#include "Body.h"
#include "s3e.h"
#include "Tail.h"
#include "Assets.h"

class Head : public Body {
private:
	bool initialised; //zmienna okreslajaca czy przeprowadzilem inicjalizacje
	void initialise(); //uzywam shared_from_this wiec czesc inicjalizacji musi byc poza konstruktorem

	std::shared_ptr<Tail>lastTail;//wskaznik do ostatniej czesci Tailu, potrzebne do dodawania kolejnych czesci
	
	//zmienne i metody potrzbne do poruszania
	float moveAngle; //odchylenie od poziomu pozwalajace sterowac, przesuwac itp
	const float moveVelocity = 3.5f; //stala predkosc przemiszczania
	const float moveAngleChange = 6.66f; //zmienna okreslajaca o ile zmienia sie kat podczas jednej klatki
	void changeMoveAngle(float pressedX, float pressedY);//wykrywa po ktorej stronie glowy nacisniety, zmienia kat
	void move(); //oblicza nowa pozycje 

	//funkcje pomocnicze
	float vectorProduct(std::pair<float, float> Pkt1, std::pair<float, float> Pkt2, std::pair<float, float> Pkt3);
public:
	Head() {};
	Head(float _lewyGornyX, float _lewyGornyY);
	void update();
    bool detectSelfCollision();//wykrywa kolizje snake'a ze swoim ogonem, 
                               //zwraca true w przypadku krytycznego zdezenia tz. z strongTail
                               //w przypadku weakTail przetnie go odcinajac to co jest za nim
	void addTail(TailType tailType); // doklada nowy ogon na koniec
};

#endif 


