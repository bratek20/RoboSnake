#include "Przycisk.h"

Przycisk::Przycisk(CIw2DImage* _grafika, float _lewyGornyX, float _lewyGornyY):grafika(_grafika),
	Prostokat(_lewyGornyX, _lewyGornyY, _grafika->GetWidth(), _grafika->GetHeight()) {}

bool Przycisk::jestNacisniety() {
	if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) == S3E_POINTER_STATE_DOWN &&
		zawiera( s3ePointerGetX(),s3ePointerGetY() ) )
			return true;
	return false;
}

void Przycisk::rysuj() {
	Iw2DDrawImage(grafika, CIwFVec2(lewyGornyX, lewyGornyY));
}