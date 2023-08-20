/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:52:14 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/16 14:37:55 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap clap("clap");
    ScavTrap scav("scav");
    scav.attack("gfdgfg");
	clap.takeDamage(6);
	scav.takeDamage(6);
	scav.beRepaired(8);
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