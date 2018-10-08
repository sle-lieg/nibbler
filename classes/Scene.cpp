#include "Scene.hpp"

Scene::Scene(int width, int height) :
_width{width}, _height{height}, _background{Color::BLUE} {}

Scene::~Scene(void) {}

int	Scene::getWidth(void) const {
	return _width;
}

int	Scene::getHeight(void) const {
	return _height;
}
