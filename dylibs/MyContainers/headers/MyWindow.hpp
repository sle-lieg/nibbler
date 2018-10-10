#ifndef MYWINDOW_HPP
# define MYWINDOW_HPP

#include <iostream>

class MyWindow
{
protected:
	int			_width;
	int			_height;
	std::string	_texture;

public:
	MyWindow(int width, int height, std::string texture = "");
	virtual ~MyWindow(void);

	virtual int					getWidth(void) const;
	virtual int					getHeight(void) const;
	virtual const std::string&	getTexture(void) const;

	// virtual void		setWidth(int width);
	// virtual void		setHeight(int height);
	// virtual void		setTexture(const std::string &texture);

private:
	MyWindow(void);
	MyWindow(MyWindow const &);
	MyWindow&	operator=(MyWindow const &);
};

#endif
