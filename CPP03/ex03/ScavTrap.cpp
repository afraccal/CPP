/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:24:57 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/16 16:51:46 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->_name = "";
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    std::cout << "Default ScavTrap built" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    this->_name = name;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    std::cout << "Scavtrap " << this->_name << " was built" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destroyed" << std::endl;
}

ScavTrap::ScavTrap(ClapTrap const &other)
{
    std::cout << "Scavtrap copied was created" << std::endl;
    *this = other;
}

ScavTrap & ScavTrap::operator = (ScavTrap const &other)
{
    std::cout << "Assignement operator was built" << std::endl;
    this->_name = other._name;
    this->energy_points = other.energy_points;
    this->hit_points = other.hit_points;
    this->attack_damage = other.attack_damage;
    return (*this);
}

void ScavTrap::guardGate(void)
{
if (this->hit_points > 0)
    std::cout << getname() << " has entered in gate keeper mode " << std::endl; 
else
    std::cout << getname() << " hit points finished" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->hit_points > 0)
    {
        if (this->energy_points <= 0)
        {
            std::cout << getname() << " energy points are finished" << std::endl;
            return;
        }
        this->energy_points--;
        std::cout << getname() << " attacks " << target << " causing " << this->hit_points << " damages " << std::endl;
    }
    else
        std::cout << getname() << " hit points are finished" << std::endl;
}