/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:06:41 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/16 16:55:02 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    this->_name = "";
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    std::cout << "Default FragTrap built" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    this->_name = name;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    std::cout << "FragTrap " << this->_name << " was built" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destroyed" << std::endl;
}

FragTrap::FragTrap(ClapTrap const &other)
{
    std::cout << "FragTrap copied was created" << std::endl;
    *this = other;
}

FragTrap & FragTrap::operator = (FragTrap const &other)
{
    std::cout << "Assignement operator was built" << std::endl;
    this->_name = other._name;
    this->energy_points = other.energy_points;
    this->hit_points = other.hit_points;
    this->attack_damage = other.attack_damage;
    return (*this);
}

void FragTrap::attack(const std::string& target)
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

void FragTrap::highFivesGuys(void)
{
    if (this->hit_points > 0)
        std::cout << getname() << " request the higher of five" << std::endl;
    else
        std::cout << getname() << " hit points are finished" << std::endl;
}