#include "Head.h"

Head::Head(float _leftTopX, float _leftTopY):
	Body(Assets::instance().head, _leftTopX, _leftTopY),moveAngle(0),initialised(false){
}

void Head::update() {
	if (!initialised)initialise();

	if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) == S3E_POINTER_STATE_DOWN) //dokadajac klase input moze byc AI
		changeMoveAngle(s3ePointerGetX(), s3ePointerGetY());
	
	move();

	if (back)back->update();
}

void Head::initialise() {
	initialised = true;
	back = std::shared_ptr<Body>(new Tail(initialTail, shared_from_this(), leftTopX, leftTopY));//tutam ustawiam tyl dla Glowy
	lastTail = std::static_pointer_cast<Tail>(back);

    addTail(initialTail); //poczatkowy snake ma glowe oraz dwa fragmenty
}

bool Head::detectSelfCollision() {
    if (!initialised)return false;

    std::weak_ptr<Tail>tailIterator = lastTail;
    while (tailIterator.lock()->getTailType() != initialTail) {
        if (collide(*tailIterator.lock())) {//wykryto kolizje z ogonem
            if (tailIterator.lock()->getTailType() == strongTail)return true;//kolizja krytyczna - koniec gry
            if (tailIterator.lock()->getTailType() == weakTail) {
                tailIterator.lock()->cutTail(); 
                lastTail = tailIterator.lock();
                return false; //kolizja z miekkim ogonem - odcinamy ale zyjemy dalej
            }
        }
        tailIterator = std::static_pointer_cast<Tail>( tailIterator.lock()->getFront().lock() );
    }
    return false;
}

void Head::addTail(TailType tailType) {
	lastTail = std::static_pointer_cast<Tail>(lastTail->addTail(tailType));
}
void Head::changeMoveAngle(float pressedX, float pressedY) {
	//pierwszy pkt to po prostu center ciala
	//drugi pkt to wyimaginowany pkt w ktorym znalazlby sie Snake poruszajac sie z aktualnym katem
	//trzeci pkt to miejsce nacisniecia 
	//jesli znak iloczyn > 0 to skrecamy w lewo tz. zwiekszamy kat poruszania, skrecajac w prawo zmniejszamy kat

	float znakIloczynu =
		vectorProduct(std::make_pair(centerX, centerY),
			std::make_pair(centerX + 10*(float)cos(moveAngle * PI/180), centerY + 10*(float)sin(moveAngle * PI/180)),
				std::make_pair(pressedX, pressedY) );

	if (znakIloczynu > 0)moveAngle += moveAngleChange;
	else if (znakIloczynu < 0)moveAngle -= moveAngleChange;
}

void Head::move() {
	if (moveAngle < 0)moveAngle += 360;
	if (moveAngle >= 360)moveAngle -= 360;

	moveToPosition(centerX + cos(moveAngle *  PI / 180) * moveVelocity,		//rozkladam vector na skladowa pozioma
		centerY + sin(moveAngle * PI / 180) * moveVelocity); //i pionowa
}

float Head::vectorProduct(std::pair<float, float> Pkt1, std::pair<float, float> Pkt2, std::pair<float, float> Pkt3) {
	Pkt3.first -= Pkt1.first; Pkt3.second -= Pkt1.second;
	Pkt2.first -= Pkt1.first; Pkt2.second -= Pkt1.second;

	return Pkt2.first*Pkt3.second - Pkt2.second*Pkt3.first;
}


