/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:52:14 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/15 16:22:11 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap("clap");
	clap.attack("Afraccal");
	clap.takeDamage(6);
    clap.attack("Afraccal");
    clap.attack("Afraccal");
    clap.attack("Afraccal");
    clap.attack("Afraccal");
    clap.attack("Afraccal");
	clap.beRepaired(8);
    clap.takeDamage(3);
    clap.takeDamage(3);
	clap.beRepaired(8);
    clap.attack("Afraccal");
	clap.beRepaired(4);
    clap.attack("Afraccal");
	clap.takeDamage(33);
    clap.takeDamage(3);
	clap.beRepaired(8);
	clap.takeDamage(17);

}