/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 18:14:05 by sle-lieg          #+#    #+#             */
/*   Updated: 2018/10/10 19:09:03 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nibbler.hpp"
#include "Game.hpp"

int main(int ac, char** av)
{
	Game	game(ac, av);

	while (game.isOpen()) {
		game.handleInputs();
		// game.updateGame();
		game.drawGame();
	}
	return (0);
}
