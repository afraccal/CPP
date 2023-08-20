/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:27:46 by afraccal          #+#    #+#             */
/*   Updated: 2023/05/31 14:48:14 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie test ("Mario");

    test.announce();

    
    Zombie *test2;
    
    test2 = newZombie ("Carlo");
    test2->announce();

    randomChump ("Giuseppe");

    delete test2;
}