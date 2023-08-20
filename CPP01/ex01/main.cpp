/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:35:43 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/06 10:38:18 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main ()
{
    int i;
    
    i = -1;
	Zombie *horde = zombieHorde(10, "Zom");
	while (++i < 10)
		horde[i].announce();
	delete [] horde;
}