#include "Prostokat.h"

Prostokat::Prostokat(float _lewyGornyX, float _lewyGornyY, float _bokPoziomy, float _bokPionowy):
	lewyGornyX(_lewyGornyX), lewyGornyY(_lewyGornyY), bokPoziomy(_bokPoziomy), bokPionowy(_bokPionowy){}

bool Prostokat::zawiera(float x, float y) { 
	if (lewyGornyX <= x && x <= lewyGornyX + bokPoziomy &&
		lewyGornyY <= y && y <= lewyGornyY + bokPionowy)
		return true;
	return false;
}

bool Prostokat::zawiera(Prostokat &innyProstokat) { 
	if (zawiera(innyProstokat.getLewyGornyX(), innyProstokat.getLewyGornyY()) &&
		zawiera(innyProstokat.getLewyGornyX(), innyProstokat.getLewyGornyY() + innyProstokat.getBokPionowy()) &&
		zawiera(innyProstokat.getLewyGornyX() + innyProstokat.getBokPoziomy(), innyProstokat.getLewyGornyY()) &&
		zawiera(innyProstokat.getLewyGornyX()+innyProstokat.getBokPoziomy(), innyProstokat.getLewyGornyY() + innyProstokat.getBokPionowy()))
		return true;
	return false;
}

bool Prostokat::koliduje(Prostokat &innyProstokat) { // czy zawieram sie w danym innym prostokacie lub czy ktorys z punktow innego prostokata jest w tym prostokacie
	if (innyProstokat.zawiera(*this) || 
		zawiera(innyProstokat.getLewyGornyX(), innyProstokat.getLewyGornyY()) ||
		zawiera(innyProstokat.getLewyGornyX(), innyProstokat.getLewyGornyY() + innyProstokat.getBokPionowy()) ||
		zawiera(innyProstokat.getLewyGornyX() + innyProstokat.getBokPoziomy(), innyProstokat.getLewyGornyY()) ||
		zawiera(innyProstokat.getLewyGornyX() + innyProstokat.getBokPoziomy(), innyProstokat.getLewyGornyY() + innyProstokat.getBokPionowy()))
		return true;
	return false;
}

float Prostokat::getLewyGornyX() { return lewyGornyX; }
float Prostokat::getLewyGornyY() { return lewyGornyY; }
float Prostokat::getBokPoziomy() { return bokPoziomy; }
float Prostokat::getBokPionowy() { return bokPionowy; }
