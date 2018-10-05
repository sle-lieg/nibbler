#include <iostream>
#include <sstream>

int main(int ac, char **av)
{
	if (ac < 3)
		exit(EXIT_FAILURE);

	std::stringstream ss;
	int width, height;

	ss << av[1] << ' ' << av[2];
	std::cout << ss.str() << std::endl;

	ss >> width >> height;
	if (ss.fail()) {
		std::cerr << "wrong input" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << "width: " << width << std::endl;
	std::cout << "height: " << height << std::endl;

	return (0);
}
