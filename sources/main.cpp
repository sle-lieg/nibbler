/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 18:14:05 by sle-lieg          #+#    #+#             */
/*   Updated: 2018/10/08 16:19:56 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nibbler.hpp"
#include "LibHandler.hpp"

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
	return new Game{width, height};
}

int main(int ac, char** av)
{
	Game		*game = initGame(ac, av);
	LibHandler	handler;

	handler.openLib(SFML);
	handler.createWin(game->getScene());
	// handler.createWindow(game->getWidth(), game->getHeight());

	while (game->isOpen()) {
		handler.handleInput(*game);
		game->updateGame();
		// handler.draw(*game);
		// handler.render();
		// break;
	}

	delete game;
	return (0);
}
