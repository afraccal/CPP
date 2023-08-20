/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 09:29:45 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/19 12:27:37 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Dog default constructor built" << std::endl;
}

Dog::Dog(const Dog &src)
{
    std::cout << "Dog copy constructor built" << std::endl;
	*this = src;
}

Dog::~Dog()
{
    std::cout << "Dog default distructor built" << std::endl;
}

Dog & Dog::operator =(const Dog &src)
{
	std::cout << "Assignement dog operator built" << std::endl;
    this->type = src.type;
	return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Wooof!!" << std::endl;
}