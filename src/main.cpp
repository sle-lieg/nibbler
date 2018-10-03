/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 18:14:05 by sle-lieg          #+#    #+#             */
/*   Updated: 2018/10/03 18:34:03 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nibbler.hpp"

int main(int ac, char** av)
{
	Libhandler	lh { SFML };

	while (true) {
		lh->get_inputs();
		lh->update();
		
	}

	return (0);
}
