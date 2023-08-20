/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:02:40 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/16 16:43:48 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Claptrap default was built" << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
{
    this->_name = name;
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
    std::cout << "Claptrap " << this->_name << " was built" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
    std::cout << "Claptrap copied was created" << std::endl;
    *this = other;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap was destroyed" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
    std::cout << "Assignement operator was built" << std::endl;
    this->_name = other._name;
    this->energy_points = other.energy_points;
    this->hit_points = other.hit_points;
    this->attack_damage = other.attack_damage;
    return (*this);
}

std::string &ClapTrap::getname()
{
    return (this->_name);
}

void ClapTrap::attack(const std::string &target)
{
    if (this->hit_points > 0)
    {
        if (this->energy_points <= 0)
        {
            std::cout << getname() << " Energy points of " << " are finished" << std::endl;
            return;
        }
        this->energy_points--;
        std::cout << getname() << " attacks " << target << " causing " << this->hit_points << " damages " << std::endl;
    }
    else
        std::cout << "Hit points of " << getname() << " finished" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_points > 0)
    {
        std::cout << getname() << " took " << amount << " damage" << std::endl;
        this->hit_points -= amount;
    }
    else
        std::cout << getname() << " Energy points of " << " are finished" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hit_points > 0)
    {
        if (this->energy_points <= 0)
        {
            std::cout << "Energy points of " << getname() << " are finished" << std::endl;
            return;
        }
        this->energy_points--;
        std::cout << getname() << " is repaired for " << amount << " points" << std::endl;	
        this->hit_points += amount;
    }
    else
        std::cout << "Hit points of " << getname() << " finished" << std::endl;
}
