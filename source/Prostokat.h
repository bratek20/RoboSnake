#ifndef Prostokat_h
#define Prostokat_h

class Prostokat {
protected:
	int lewyGornyX, lewyGornyY, bokPoziomy, bokPionowy;

public:
	Prostokat() {}
	~Prostokat() {}
	Prostokat(int _lewyGornyX, int _lewyGornyY, int _bokPoziomy, int _bokPionowy);
	
	bool zawiera(int x, int y); // czy pkt (x,y) zawiera sie w prostokacie
	bool zawiera(Prostokat &innyProstokat);// czy prostokat w calosci zawiera dany inny prostokat
	bool koliduje(Prostokat &innyProstokat); // czy prostokat jakos koliduje z innym prostokatem

	int getLewyGornyX();
	int getLewyGornyY();
	int getBokPoziomy();
	int getBokPionowy();
};

#endif 

