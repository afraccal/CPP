/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:54:33 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/19 14:00:53 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "A weird animal";
    std::cout << "WrongAnimal default constructor built" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
    std::cout << "WrongAnimal copy constructor built" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal default destructor built" << std::endl;
}

WrongAnimal & WrongAnimal::operator =(const WrongAnimal &src)
{
	std::cout << "Assignement WrongAnimal operator built" << std::endl;
	this->type = src.getType();
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "The WrongAnimals are making some weird noise" << std::endl;
}

const std::string WrongAnimal::getType() const
{
	return(type);
}
