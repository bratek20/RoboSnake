#include "Zasoby.h"

Zasoby::Zasoby(){
	przyciskStart = Iw2DCreateImage("textures/przyciskStart.png");
	przyciskWyjscie = Iw2DCreateImage("textures/przyciskWyjscie.png");
}
Zasoby::~Zasoby() {
	delete przyciskStart;
	delete przyciskWyjscie;
}