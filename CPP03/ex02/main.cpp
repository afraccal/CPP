/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:52:14 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/16 16:55:46 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	int i = -1;
	ClapTrap clap("clap");
    ScavTrap scav("scav");
	FragTrap frag("frag");
	clap.attack("giulio");
	frag.attack("franco");
    scav.attack("aldo");
	while (++i < 100)
		frag.attack("massimo");
	frag.highFivesGuys();
	clap.takeDamage(6);
	scav.takeDamage(6);
	frag.beRepaired(8);
    clap.takeDamage(3);
	scav.guardGate();
    clap.attack("Afraccal");
	clap.beRepaired(4);
    clap.attack("Afraccal");
	clap.takeDamage(33);
    clap.takeDamage(3);
	scav.takeDamage(300);
	scav.beRepaired(300);
	clap.beRepaired(8);
	clap.takeDamage(17);

}