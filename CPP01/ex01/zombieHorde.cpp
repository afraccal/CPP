/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:34:27 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/06 10:34:11 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    int i;
    Zombie *hordezom;

    i = -1;
    hordezom = new Zombie[N];
    while (++i < N)
    {
        hordezom[i].SetName(name);
    }
    return(hordezom);
}