#include "MyWindow.hpp"

MyWindow::MyWindow(int width, int height, std::string texture) :
	_width{width}, _height{height}, _texture{texture}
{

}

MyWindow::~MyWindow(void) {}


int					MyWindow::getWidth(void) const { return _width; }
int					MyWindow::getHeight(void) const { return _height; }
const std::string&	MyWindow::getTexture(void) const { return _texture; }

// TODO: CHECK MIN & MAX WIDTH ??
void	MyWindow::setWidth(int width) {
	_width = width;
}
// TODO: CHECK MIN & MAX HEIGHT ??
void	MyWindow::setHeight(int height) {
	_height = height;
}

void	MyWindow::setTexture(const std::string &texture) {
	_texture = texture;
}
