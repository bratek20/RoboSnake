#ifndef Reward_h
#define Reward_h

#include "Rectangle.h"
#include "Tail.h"
#include "Iw2D.h"
#include "Assets.h"

class Reward : public Rectangle {
private:
    CIw2DImage* image;
    bool visible; //czy jest widoczne na ekranie
    int currentTime; //aktualny czas potrzebny do okreslenia widocznosci
    const int spawnTime = 10; // czas w klatkach co ile pojawia sie nowa nagroda
    TailType rewardType; //rodzaj nagrody
    void reset(); //ustawia nowa nagrode, jej pozycje typ itp
public:
    Reward();
    void update();
    void draw();
    bool isVisible();
    TailType claimReward(); //zwraca typ nagordy oraz resetuje mechanizm nagrod
    
};
#endif 

