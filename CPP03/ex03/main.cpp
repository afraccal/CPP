/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:52:14 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/16 16:35:40 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	ClapTrap clap("clap");
    ScavTrap scav("scav");
    FragTrap frag("frag");
	DiamondTrap diam("diam");
	clap.attack("Foggia");
	frag.attack("Bari");
    scav.attack("Lecce");
	diam.attack("Brindisi");
	frag.highFivesGuys();
	clap.takeDamage(6);
	diam.takeDamage(9);
	clap.beRepaired(8);
	diam.whoamI();
	clap.takeDamage(17);
	
}