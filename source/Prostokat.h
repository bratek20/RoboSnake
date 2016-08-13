#ifndef Prostokat_h
#define Prostokat_h

class Prostokat {
protected:
	float lewyGornyX, lewyGornyY, bokPoziomy, bokPionowy;

public:
	Prostokat() {}
	~Prostokat() {}
	Prostokat(float _lewyGornyX, float _lewyGornyY, float _bokPoziomy, float _bokPionowy);
	
	bool zawiera(float x, float y); // czy pkt (x,y) zawiera sie w prostokacie
	bool zawiera(Prostokat &innyProstokat);// czy prostokat w calosci zawiera dany inny prostokat
	bool koliduje(Prostokat &innyProstokat); // czy prostokat jakos koliduje z innym prostokatem

	float getLewyGornyX();
	float getLewyGornyY();
	float getBokPoziomy();
	float getBokPionowy();
};

#endif 

