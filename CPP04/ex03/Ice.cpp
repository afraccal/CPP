/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:42:42 by afraccal          #+#    #+#             */
/*   Updated: 2023/06/22 15:17:13 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice default built" << std::endl;
}

Ice::Ice(const Ice &src) : AMateria("ice")
{
    std::cout << "Copy Ice default built" << std::endl;
    *this = src;
}

Ice::~Ice()
{
    std::cout << "Ice destroyed" << std::endl;
}

Ice &Ice::operator=(const Ice &src)
{
    std::cout << "Assignement Ice built" << std::endl;
    this->_type = src._type;
    return (*this);
}

AMateria *Ice::clone() const
{
    return(new Ice(*this));
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}


