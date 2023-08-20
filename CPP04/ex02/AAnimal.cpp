/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 09:11:45 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/20 13:34:54 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::~AAnimal()
{
    std::cout << "AAnimal default destructor built" << std::endl;
}

AAnimal & AAnimal::operator =(const AAnimal &src)
{
	std::cout << "Assignement AAnimal operator built" << std::endl;
	this->type = src.getType();
	return (*this);
}

void AAnimal::makeSound() const
{
	std::cout << "The AAnimals are making some noise" << std::endl;
}

const std::string AAnimal::getType() const
{
	return(type);
}
