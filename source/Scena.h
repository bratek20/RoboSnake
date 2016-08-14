#ifndef Scena_h 
#define Scena_h

#include <memory>

class Scena {
public:
	Scena();
	virtual ~Scena(){} //nie usuwam nastepnaScena poniewaz bedize wykorzystwana po smierci tego obiektu
	virtual void uaktualnij()=0;
	virtual void rysuj()=0;
	Scena* jakaNastepnaScena();
protected:
	Scena* nastepnaScena;
};

#endif 

