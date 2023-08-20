/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 09:29:05 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/20 12:09:20 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat default constructor built" << std::endl;
}

Cat::Cat(const Cat &src)
{
    std::cout << "Cat copy constructor built" << std::endl;
	*this = src;
    this->brain = new Brain();
}

Cat::~Cat()
{
    std::cout << "Cat default destructor built" << std::endl;
    delete this->brain;
}

Cat & Cat::operator =(const Cat &src)
{
	std::cout << "Assignement cat operator built" << std::endl;
    this->type = src.type;
    this->brain = src.brain;
	return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Meowww!!" << std::endl;
}

Brain *Cat::getBrain() const
{
    return(this->brain);
}