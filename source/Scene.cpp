#include "Scene.h"

Scene::Scene():nextScene(nullptr){}

Scene* Scene::whatNextScene() {
	return nextScene;
}
