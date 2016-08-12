#include "Prostokat.h"

Prostokat::Prostokat(int _lewyGornyX, int _lewyGornyY, int _bokPoziomy, int _bokPionowy):
	lewyGornyX(_lewyGornyX), lewyGornyY(_lewyGornyY), bokPoziomy(_bokPoziomy), bokPionowy(_bokPionowy){}

bool Prostokat::zawiera(int x, int y) { 
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

int Prostokat::getLewyGornyX() { return lewyGornyX; }
int Prostokat::getLewyGornyY() { return lewyGornyY; }
int Prostokat::getBokPoziomy() { return bokPoziomy; }
int Prostokat::getBokPionowy() { return bokPionowy; }
