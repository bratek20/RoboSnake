#include "Przycisk.h"

Przycisk::Przycisk(CIw2DImage* _ikona, int _lewyGornyX, int _lewyGornyY):ikona(_ikona),
	Prostokat(_lewyGornyX, _lewyGornyY, _ikona->GetWidth(), _ikona->GetHeight()) {}

bool Przycisk::jestNacisniety() {
	if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) == S3E_POINTER_STATE_DOWN &&
		zawiera( s3ePointerGetX(),s3ePointerGetY() ) )
			return true;
	return false;
}

void Przycisk::rysuj() {
	Iw2DDrawImage(ikona, CIwFVec2(lewyGornyX, lewyGornyY));
}