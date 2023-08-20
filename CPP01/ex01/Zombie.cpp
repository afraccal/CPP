/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:35:38 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/06 10:32:50 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce (void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie (void)
{ 
}

Zombie::Zombie (std::string name)
{
    this->name = name;
}
    
Zombie::~Zombie(void)
{
    std::cout << this->name << " deconstruted" << std::endl;
}

void    Zombie::SetName(std::string name)
{
    this->name = name;
}