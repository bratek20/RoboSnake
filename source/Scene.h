#ifndef Scene_h 
#define Scene_h

#include <memory>

class Scene {
public:
	Scene();
	virtual ~Scene(){} //nie usuwam nastepnaScene poniewaz bedize wykorzystwana po smierci tego obiektu
	virtual void update()=0;
	virtual void draw()=0;
	Scene* whatNextScene();
protected:
	Scene* nextScene;
};

#endif 

