/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:53:22 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/19 13:58:58 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "WrongCat default constructor built" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src)
{
    std::cout << "WrongCat copy constructor built" << std::endl;
	*this = src;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat default distructor built" << std::endl;
}

WrongCat & WrongCat::operator =(const WrongCat &src)
{
	std::cout << "Assignement WrongCat operator built" << std::endl;
    this->type = src.type;
	return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "Cip cip!!" << std::endl;
}