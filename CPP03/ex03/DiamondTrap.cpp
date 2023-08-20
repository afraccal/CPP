/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:26:23 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/16 16:56:57 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    this->_name = "Default";
    ClapTrap::_name = "Default_clap_name";
    this->hit_points = FragTrap::hit_points;
    this->energy_points = ScavTrap::energy_points;
    this->attack_damage = FragTrap::attack_damage;
    std::cout << "Default DiamondTrap built" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
    this->_name = name;
    ClapTrap::_name = name + "_clap_name";
    this->hit_points = FragTrap::hit_points;
    this->energy_points = ScavTrap::energy_points;
    this->attack_damage = FragTrap::attack_damage;
    std::cout << "DiamondTrap " << this->_name << " was built" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destroyed" << std::endl;
}

DiamondTrap::DiamondTrap(ClapTrap const &other)
{
    std::cout << "DiamondTrap copied was created" << std::endl;
    *this = other;
}

DiamondTrap & DiamondTrap::operator = (DiamondTrap const &other)
{
    std::cout << "Assignement operator was built" << std::endl;
    this->_name = other._name;
    this->energy_points = other.energy_points;
    this->hit_points = other.hit_points;
    this->attack_damage = other.attack_damage;
    return (*this);
}

void DiamondTrap::whoamI(void)
{
if (this->hit_points > 0)
    std::cout << _name << " is my name, but also " << ClapTrap::_name << " is my name" << std::endl; 
else
    std::cout << getname() << " hit points are finished" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
   ScavTrap::attack(target);
}
