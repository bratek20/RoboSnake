#ifndef Reward_h
#define Reward_h

#include "Rectangle.h"
#include "Tail.h"
#include "Iw2D.h"
#include "Assets.h"
#include "Head.h"
#include "Obstacle.h"

class Reward : public Rectangle {
private:
    CIw2DImage* image;
    std::vector<Obstacle>obstacles;//referencja do przeskzod na scenie gry 
                                   //pomaga przy poprawnym wylosowaniu pozycji dla nagrody (nie na przeszkodach)
    bool visible; //czy jest widoczne na ekranie
    int currentTime; //aktualny czas potrzebny do okreslenia widocznosci
    const int spawnTime = 10; // czas w klatkach co ile pojawia sie nowa nagroda
    const int rewardAmount = 3; //ilosc przydzielen nagrody - o ile segmentow wydluzy sie snake przy jednym zebraniu
    const int strongTailPropability = 3111; //szansa na pojawienie sie jako nagordy strongTail wynosi 1/strongTailPopability
    TailType rewardType; //rodzaj nagrody
    void reset(); //ustawia nowa nagrode, jej pozycje typ itp
    void randomPosition();//losuje nowa pozycje nagrody tak aby nie kolidowala z przeszkodami na scenie gry
public:
    Reward(std::vector<Obstacle> & _obstacles);
    void update();
    void draw();
    bool isVisible();
    void claimReward(std::shared_ptr<Head> snake); //nagradza snake'a oraz resetuje mechanizm nagrod
    
};
#endif 

