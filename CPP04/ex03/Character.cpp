/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:56:11 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/22 15:17:31 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
    this->_name = "";
    int i = -1;
    while (++i < 4)
		this->inventory[i] = NULL;
	std::cout << "Default Character built" << std::endl;
}

Character::Character(std::string pers)
{
	this->_name = pers;
    int i = -1;
    while (++i < 4)
		this->inventory[i] = NULL;
	std::cout << "Default Character built" << std::endl;
}

Character::Character(Character const &src)
{
	std::cout << "Copy Character built" << std::endl;
	*this = src;
}

Character::~Character(void)
{
	std::cout << "Character destroyed" << std::endl;
}

Character &	Character::operator=(Character const &src)
{
	int i = -1;
	this->number_equipped = 0;
    while (++i < 4)
	{
		if (this->inventory[i])
			delete this->inventory[i];
		this->inventory[i] = src.inventory[i];
		if(src.inventory[i])
			this->number_equipped++;
	}
	this->_name = src.getName();
	std::cout << "Assignement Character built" << std::endl;
	return (*this);
}

std::string const	&Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if(this->number_equipped < 4)
	{
		this->inventory[this->number_equipped] = m;
		number_equipped++;
		std::cout << m->getType() << " equipped" << std::endl;
	}
	else
	{
		std::cout << "Inventory is full" << std::endl;
	}
}

void Character::unequip(int idx)
{
	int i;

	i = idx + 1;
	while (i < 4 && this->inventory[i])
	{
		this->inventory[i - 1] = this->inventory[i];
		i++;
	}
	this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if(this->inventory[idx])
		this->inventory[idx]->use(target);
	else
		std::cout << "No materia equipped" << std::endl;
}