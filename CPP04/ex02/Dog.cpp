/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 09:29:45 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/20 12:09:15 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog default constructor built" << std::endl;
}

Dog::Dog(const Dog &src)
{
    std::cout << "Dog copy constructor built" << std::endl;
    this->brain = new Brain();
	*this = src;
}

Dog::~Dog()
{
    std::cout << "Dog default destructor built" << std::endl;
    delete this->brain;
}

Dog & Dog::operator =(const Dog &src)
{
	std::cout << "Assignement dog operator built" << std::endl;
    this->type = src.type;
    this->brain = src.brain;
	return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Wooof!!" << std::endl;
}

Brain *Dog::getBrain() const
{
    return(this->brain);
}