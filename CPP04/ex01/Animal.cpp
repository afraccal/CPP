/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 09:11:45 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/19 14:00:59 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Animal";
    std::cout << "Animal default constructor built" << std::endl;
}

Animal::Animal(const Animal &src)
{
    std::cout << "Animal copy constructor built" << std::endl;
	*this = src;
}

Animal::~Animal()
{
    std::cout << "Animal default destructor built" << std::endl;
}

Animal & Animal::operator =(const Animal &src)
{
	std::cout << "Assignement animal operator built" << std::endl;
	this->type = src.getType();
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "The animals are making some noise" << std::endl;
}

const std::string Animal::getType() const
{
	return(type);
}
