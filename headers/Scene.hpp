#ifndef SCENE_HPP
# define SCENE_HPP

# include "enumTypes.hpp"

class Scene
{
private:
	int		_width;
	int		_height;
	// Color	_background;

	Scene(void);
	Scene(Scene const &);
	Scene&	operator=(Scene const &);

public:
	Scene(int width, int height);
	~Scene(void);

	int	getWidth(void) const;
	int	getHeight(void) const;
};

#endif
