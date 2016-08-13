#ifndef Scena_h 
#define Scena_h

#include <memory>

class Scena {
public:
	Scena();
	virtual ~Scena() {}
	virtual void uaktualnij()=0;
	virtual void rysuj()=0;
	Scena* jakaNastepnaScena();
protected:
	Scena* nastepnaScena;
};

#endif 

