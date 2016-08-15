#include "Button.h"

Button::Button(CIw2DImage* _image, float _leftTopX, float _leftTopY):image(_image),
	Rectangle(_leftTopX, _leftTopY, _image->GetWidth(), _image->GetHeight()) {}

bool Button::isPressed() {
	if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) == S3E_POINTER_STATE_DOWN &&
		contain( s3ePointerGetX(),s3ePointerGetY() ) )
			return true;
	return false;
}

void Button::draw() {
	Iw2DDrawImage(image, CIwFVec2(leftTopX, leftTopY));
}