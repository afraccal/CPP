/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 09:29:05 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/19 12:26:56 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Cat default constructor built" << std::endl;
}

Cat::Cat(const Cat &src)
{
    std::cout << "Cat copy constructor built" << std::endl;
	*this = src;
}

Cat::~Cat()
{
    std::cout << "Cat default distructor built" << std::endl;
}

Cat & Cat::operator =(const Cat &src)
{
	std::cout << "Assignement cat operator built" << std::endl;
    this->type = src.type;
	return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Meowww!!" << std::endl;
}