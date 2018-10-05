/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 18:14:05 by sle-lieg          #+#    #+#             */
/*   Updated: 2018/10/05 18:02:36 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nibbler.hpp"

static const int GAME_SIDE_MIN = 300;
static const int GAME_SIDE_MAX = 1500;

static Game	*initGame(int ac, char **av)
{
	if (ac < 3) {
		std::cout << "usage: nibbler";
		std::cout << " " << GAME_SIDE_MIN << "<=WIDTH<" << GAME_SIDE_MAX;
		std::cout << " " << GAME_SIDE_MIN << "<=HEIGHT<" << GAME_SIDE_MAX << std::endl;
		exit(EXIT_FAILURE);
	}

	std::stringstream	ss;
	int					width;
	int					height;

	ss << av[1] << ' ' << av[2];
	ss >> width >> height;
	if (ss.fail() || width < GAME_SIDE_MIN || width > GAME_SIDE_MAX
				|| height < GAME_SIDE_MIN || height > GAME_SIDE_MAX) {
		std::cout << "usage: nibbler";
		std::cout << " " << GAME_SIDE_MIN << "<=WIDTH<" << GAME_SIDE_MAX;
		std::cout << " " << GAME_SIDE_MIN << "<=HEIGHT<" << GAME_SIDE_MAX << std::endl;
		exit(EXIT_FAILURE);
	}
	return new Game {width, height};
}

int main(int ac, char** av)
{
	Game	*game = initGame(ac, av);
	


	delete game;
	return (0);
}
