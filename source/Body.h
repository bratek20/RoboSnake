#ifndef Body_h
#define Body_h

#include "Rectangle.h"
#include "Iw2D.h"
#include "algorithm"
#include "queue"
#include "memory"
#include "cmath"

// cialo dla snake'a, bedzie dziedziczone przez glowe oraz tulow
// pozwalam na shared_from_this bo bede potrzebowac tego aby tworzyc weak_ptr

class Body : public Rectangle, public std::enable_shared_from_this<Body> { 
private:																	
	CIw2DImage* image;

	std::queue< std::pair<float, float> >movesMemory; // zachowuje ostatnie kilka ruchow, potrzebne do przemieszczania sie fragmentow snake'a  
	//funkcje pomocnicze
	void saveMove(float nowyX, float nowyY);//doklada nowa pozycje do pamieciRuchow
	void setPosition(float nowySrodekX, float nowySrodekY);//ustawia nowa pozycje, poprawiajac rowniez ulozenie prostokata
	float distance(std::pair<float, float> Pkt1, std::pair<float, float> Pkt2);//oblicza odleglosc euklidesowa
protected:
	//wskazniki ustawiane sa w klasach ktore beda dziedziczyc
	std::weak_ptr<Body>front;//wskaznik na czesc ciala przede mna, ktory mnie utworzyl i za nim podazam
	std::shared_ptr<Body>back;//wskaznik na czesc ciala ktory utworzylem i ktory za mna podaza

	float radius; // snake bedzie skladac sie z okregow
	float centerX, centerY; //srodek ciala (okregu)
	const std::pair<float, float> noEnoughMemory = std::make_pair(-1, -1); // zwracane gdy kolejka nie pamieta conajmniej maxPamiecRuchow
	void moveToPosition(float nowyX, float nowyY);//przemiszcza cialo na pozycje (nowyX, nowyY), zapamietujac ruch

    void setImage(CIw2DImage* _image); //ustawia inna grafike 
public:
	Body(){}
	Body(CIw2DImage* _grafika, float _lewyGornyX, float _lewyGornyY);//grafika powinna przedstawiac okrag
	virtual void update() = 0;
	void draw();
	std::pair<float, float> lastMove(); //zwraca ostatni zapamietany ruch, potrzebne aby ogon ladnie za soba podazal
    std::weak_ptr<Body> getFront();//zwraca wskaznik na moj przod
};
#endif 
